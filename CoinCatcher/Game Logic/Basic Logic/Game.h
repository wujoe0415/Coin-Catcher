#pragma once
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include "Entity.h"
#include "Player.h"
#include "Coin.h"
#include "System/Window.h"

using namespace std;

class Game : IDrawable {
private:
	char* filename;
	char* filename2;
	Player* player;
	vector<Coin*> coins;
	Window* window;
public:
	Game();
	void setGameMode(unsigned int mode);
	void timer(void(*t)(int));
	void Draw();
	bool DetectCollision(Entity* entity1, Entity* entity2);
	bool FallBack(Entity*);
	void SpawnCoin();
	void MoveCoin();
	void CollectCoin(Coin*);
	void DropCoin(Coin*);
	void DeleteCoins(vector<int>&);
	void GameLoop();
	void PauseGame();
};