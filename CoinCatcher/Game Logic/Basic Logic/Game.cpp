#include "Game.h"
#include <time.h>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "System/stb_image.h"

SpriteRenderer    *Renderer;

Game::Game() {
	window = &Window::getInstance();
	// Inititialize Render Data
	ResourceManager::LoadShader("quad.vert", "quad.frag", nullptr, "standard");
	ResourceManager::LoadTexture("Resources/miner.png", true, "player");
	ResourceManager::LoadTexture("Resources/diamond.png", true, "coin");
	ResourceManager::LoadTexture("Resources/malware.png", true, "bomb");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->getWindowWidth()), static_cast<float>(window->getWindowHeight()), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("standard").Use().SetInteger("standard", 0);
	ResourceManager::GetShader("standard").SetMatrix4("standard", projection);

	Shader standardSprite = ResourceManager::GetShader("standard") /*loadShaderFromFile("quad.vert", "quad.frag", nullptr)*/;
	Renderer = new SpriteRenderer(standardSprite);

	standardSprite.Use();
	glUniform1i(glGetUniformLocation(standardSprite.ID, "sprite"), 0);
	vector<int> inputList{ GLFW_KEY_SPACE };
	keyinputs = new KeyInput(inputList);
	InitGame();
} 
void Game::InitGame() {
	coins.clear();
	bombs.clear();
	player = new Player(120, 300, "player", "standard", 10, 5);
	ScoreUI = new UI();
	ScoreUI->LoadGameUI();
	totalTime = 0;
	updateCoinCycle = 0.5;
	currentCoinTime = 0;
	currentBombTime = 0;
	collectedCoinNum = 0;
	updateBombCycle = 0.8;
	gameTime = 60; 
	glfwSetTime(0);
	isEnd = false;
}
void Game::ReGame() {
	if (keyinputs->getIsKeyDown(GLFW_KEY_SPACE)) {
		InitGame();
	}
}
void Game::setGameMode(unsigned int mode)
{
	int health = 100;
	switch (mode) {
	case 0: health = 120; break;
	case 1: health = 100; break;
	case 2: health = 80; break;
	}
	player->setHealth(health);
}

// found in OpenGL Game Development by Example just rewrote to be compatible with this program 
void Game::SpawnCoin(float deltaTime) {
	currentCoinTime += deltaTime;
	if (currentCoinTime < updateCoinCycle)
		return;
	int random = rand();
	for (int i = random % 2; i >= 0; i--) {
		Coin* coin = new Coin(100, 80, "coin", "standard", 7, ((float)(random % 8) / 10) * 5);


		float spawnX = coin->getWidth() + (float)((float)(random % 100) / 100) * window->getWindowWidth();
		coin->setPositionX(spawnX);

		coins.push_back(coin);
	}
	currentCoinTime = 0;
	updateCoinCycle = (float)(random % 50) / 100 + 0.2f;
}
void Game::SpawnBomb(float deltaTime) {
	currentBombTime += deltaTime;
	if (currentBombTime < updateBombCycle)
		return;
	int random = rand();
	Bomb* bomb = new Bomb(70, 70, "bomb", "standard", 7, ((float)(random % 8) / 10) * 5, 1);

	float spawnX = bomb->getWidth() + (float)((float)(random % 100) / 100) * window->getWindowWidth();
	std::cout << spawnX << std::endl;
	bomb->setPositionX(spawnX);
	bombs.push_back(bomb);

	currentBombTime = 0;
	updateBombCycle = (float)(random % 80) / 100 + 0.8f;
}


void Game::MoveCoin() {
	for (auto& coin : coins) {
		coin->MoveDown();
		coin->Rotation();
	}
}
void Game::Draw() {
	if (isEnd) {
		ScoreUI->DrawEndUI(*Renderer, collectedCoinNum);
		return;
	}
	if (player != nullptr) 
		player->Draw(*Renderer);
	if (ScoreUI != nullptr)
		ScoreUI->Draw(*Renderer, collectedCoinNum, gameTime - totalTime + 1);
	for (auto coin : coins) 
		coin->Draw(*Renderer);
	for (auto bomb : bombs)
		bomb->Draw(*Renderer);
}

// AABB (axis-aligned bounding box) collision
bool Game::DetectCollision(Entity* entity1, Entity* entity2) {
	if (entity2 == nullptr) {
		return false;
	}
	bool collisionX = entity1->getPositionX() + entity1->getWidth() >= entity2->getPositionX() &&
		entity2->getPositionX() + entity2->getWidth() >= entity1->getPositionX();
	bool collisionY = entity1->getPositionY() + entity1->getHeight() >= entity2->getPositionY() &&
		entity2->getPositionY() + entity2->getHeight() >= entity1->getPositionY();

	return collisionX && collisionY;
}
bool Game::FallBack(Entity* entity) {
	return entity->getPositionY() + entity->getHeight() < player->getPositionY() + player->getHealth();
}

void Game::CollectCoin(Coin* coin) {
	collectedCoinNum++;
}
void Game::TouchBomb() {
	player->setHealth(player->getHealth() - bombs[0]->mDamage);
	if (player->getHealth() <= 0) { // Check Game Over
		EndGame();
	}
}
void Game::DeleteCoins(vector<int>& needDeletedIndex) {
	for (int i = needDeletedIndex.size() - 1; i >= 0; i--) {
		Coin* coin = coins[needDeletedIndex[i]];
		coins.erase(coins.begin() + needDeletedIndex[i]);
		free(coin);
	}
}
void Game::PauseGame() {}
void Game::EndGame() {
	isEnd = true;
	//exit(0);
}
void Game::GameLoop() {
	if (isEnd) {
		ReGame();
		return;
	}
	if (totalTime > gameTime)
		EndGame();
	float deltaTime = glfwGetTime() - totalTime;
	totalTime = glfwGetTime();
	SpawnCoin(deltaTime);
	SpawnBomb(deltaTime);

	// Player Move
	player->InputHandler();
	for (auto coin : coins)
		coin->MoveDown();
	for (auto bomb : bombs)
		bomb->MoveDown();

	// Collision Detection
	vector<int> deletedIndex;
	for (int i = 0; i < coins.size();i++) {
		if (DetectCollision(player, coins[i]))
		{
			CollectCoin(coins[i]);
			deletedIndex.push_back(i);
		}
		else if (FallBack(coins[i])) {
			deletedIndex.push_back(i);
		}
	}
	for (int i = 0; i < bombs.size();i++) {
		if (DetectCollision(player, bombs[i]))
			TouchBomb();
	}
	if (!deletedIndex.empty())
		DeleteCoins(deletedIndex);
}