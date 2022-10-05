#include "Game.h"
#include <time.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include "System/stb_image.h"



SpriteRenderer    *Renderer;

Game::Game() {
	window = &Window::getInstance();
	// Inititialize Render Data
	//ResourceManager::LoadShader("quad.vert", "quad.frag", nullptr, "standard");
	ResourceManager::LoadTexture("dino.png", true, "player");
	ResourceManager::LoadTexture("coin.png", true, "coin");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->getWindowWidth()), static_cast<float>(window->getWindowHeight()), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("standard").Use().SetInteger("standard", 0);
	ResourceManager::GetShader("standard").SetMatrix4("standard", projection);

	Shader standardSprite = loadShaderFromFile("quad.vert", "quad.frag", nullptr);
	Renderer = new SpriteRenderer(standardSprite);

	standardSprite.Use();
	glUniform1i(glGetUniformLocation(standardSprite.ID, "sprite"), 0);

	player = new Player(50, 50, "player", "standard", 10, 5);
	totalTime = 0;
	updateCoinCycle = 0.5;
	currentCoinTime = 0;
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
	for (int i = rand() % 3; i >= 0; i--) {
		Coin* coin = new Coin(70, 70, "coin", "standard", 10, 10, 1);

		float marginX = coin->getWidth();
		float marginY = coin->getHeight();

		float spawnX = (marginX / 2) + (rand() % window->getWindowWidth() - marginX);
		float spawnY = marginY; //(marginY / 2)+ (rand() % window->getWindowHeight() - marginY)

		coin->setPositionX(spawnX);
		coin->setPositionY(spawnY);

		coins.push_back(coin);
	}
	currentCoinTime = 0;
}


void Game::MoveCoin() {
	for (auto& coin : coins) {
		coin->MoveDown();
		coin->Rotation();
	}
}

void Game::Draw() {
	if (player != nullptr) 
		player->Draw(*Renderer);
	for (auto coin : coins) 
		coin->Draw(*Renderer);
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
}
void Game::DropCoin(Coin* coin) {
	player->setHealth(player->getHealth() - coin->damage);

	if (player->getHealth() <= 0) { // Check Game Over
		// Lose
		exit(0);
	}
}
void Game::DeleteCoins(vector<int>& needDeletedIndex) {
	for (int i = needDeletedIndex.size() - 1; i >= 0; i--) {
		Coin* coin = coins[needDeletedIndex[i]];
		coins.erase(coins.begin() + needDeletedIndex[i]);
		free(coin);
	}
}
void Game::PauseGame() {
}
void Game::GameLoop() {
	float deltaTime = glfwGetTime() - totalTime;
	totalTime = glfwGetTime();

	//SpawnCoin(deltaTime);

	// Player Move
	player->InputHandler();

	// Collision Detection
	vector<int> deletedIndex;
	for (int i = 0; i < coins.size();i++) {
		if (DetectCollision(player, coins[i]))
		{
			CollectCoin(coins[i]);
			deletedIndex.push_back(i);
		}
		else if (FallBack(coins[i])) {
			//DropCoin(coins[i]);
			//deletedIndex.push_back(i);
		}
	}
	if (!deletedIndex.empty())
		DeleteCoins(deletedIndex);

	// UI
}
Shader Game::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		// if geometry shader path is present, also load a geometry shader
		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}
	const char *vShaderCode = vertexCode.c_str();
	const char *fShaderCode = fragmentCode.c_str();
	const char *gShaderCode = geometryCode.c_str();
	// 2. now create shader object from source code
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	return shader;
}
Texture2D Game::loadTextureFromFile(const char *file, bool alpha)
{
	// create texture object
	Texture2D texture;
	if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}
	// load image
	int width, height, nrChannels;
	unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
	// now generate texture
	texture.Generate(width, height, data);
	// and finally free image data
	stbi_image_free(data);
	return texture;
}