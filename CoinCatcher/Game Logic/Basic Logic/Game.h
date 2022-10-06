#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Entity.h"
#include "Player.h"
#include "Coin.h"
#include "Bomb.h"
#include "UI.h"
#include "System/Window.h"
#include "System/Resource_Manager.h"
#include <glm/glm.hpp>
using namespace std;

class Game : IDrawable {
private:
	char* filename;
	char* filename2;
	Player* player;
	UI* ScoreUI;
	vector<Coin*> coins;
	vector<Bomb*> bombs;
	Window* window;
	float gameTime;
	float totalTime;
	float updateCoinCycle;
	float updateBombCycle;
	float currentCoinTime;
	float currentBombTime;
	int collectedCoinNum;

public:
	Game();
	void setGameMode(unsigned int mode);
	void Draw();
	bool DetectCollision(Entity* entity1, Entity* entity2);
	bool FallBack(Entity*);
	void SpawnCoin(float);
	void SpawnBomb(float);
	void MoveCoin();
	void CollectCoin(Coin*);
	void TouchBomb();
	void DeleteCoins(vector<int>&);
	void GameLoop();
	void PauseGame();
	void EndGame();
	void InitGame();
};