#include "Game.h"
#include <time.h>

Game::Game() {
	ResourceManager::LoadTexture("../../Resources/Sprite/player.bmp", false, "player");
	ResourceManager::LoadTexture("../../Resources/Sprite/coin.png", false, "coin");
	
	player = new Player(100, 100, "player" , 10, 5);
	window = &Window::getInstance();
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
void Game::SpawnCoin() {
	Coin* coin = new Coin(70, 70, "coin", 10, 10, 1);

	float marginX = coin->getWidth();
	float marginY = coin->getHeight();

	float spawnX = (rand() % window->getWindowWidth() - (marginX * 2)) + marginX;
	float spawnY = window->getWindowHeight() - ((rand() % (int)(player->getHeight() - (marginY * 2))) + marginY);

	coin->setPositionX(spawnX);
	coin->setPositionY(spawnY);

	coins.push_back(coin);
}


void Game::MoveCoin() {
	for (auto& coin : coins) {
		coin->MoveDown();
		coin->Rotation();
	}
}

void Game::timer(void(*t)(int)) {

}

void Game::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cout << "Draw Start\n";
	if (player != nullptr) {
		player->Draw();
	}
	for(auto coin : coins)
		coin->Draw();

	glfwSwapBuffers(window->sWindow);

	glFlush();
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
	Draw();

	if (rand() % 100 > 30)
		SpawnCoin();

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
	DeleteCoins(deletedIndex);

	// UI
}