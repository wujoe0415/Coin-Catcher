#include "Game.h"
#include <time.h>

Game::Game() {
	/*filename = _strdup("res/player2_2.bmp");
	filename2 = _strdup("res/enemy_2.bmp");
	filename3 = _strdup("res/bullet.bmp");*/
	player = new Player(100, 100, filename, 10, 5);
	window = &Window::instance();
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
	Coin* coin = new Coin(70, 70, filename2, 10, 10, 1);

	float marginX = coin->getWidth();
	float marginY = coin->getHeight();

	float spawnX = (rand() % window->getWindowWidth - (marginX * 2)) + marginX;
	float spawnY = window->getWindowHeight - ((rand() % (int)(player->getHeight() - (marginY * 2))) + marginY);

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

	for (auto coin : coins) {
		if (DetectCollision(player, coin)) {
			CollectCoin(coin);
			player->setHealth(player->getHealth() - coin->damage);
			if (player->getHealth() <= 0) {
				// Lose
				exit(0);
			}
		}
	}
}

void Game::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(player != nullptr)
		player->Draw();
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
void Game::CollectCoin(Coin* collectableCoin) {
	for (auto it = coins.begin(); it != coins.end();it = next(it)) {
		if (collectableCoin == *it) {
			coins.erase(it);
			break;
		}
	}
	free(&collectableCoin);
}
void Game::PauseGame() {
}