#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Entity.h"
#include "Player.h"
#include "Coin.h"
#include "System/Window.h"
#include "System/Resource_Manager.h"
#include <glm/glm.hpp>

using namespace std;

class Game : IDrawable {
private:
	char* filename;
	char* filename2;
	Player* player;
	vector<Coin*> coins;
	Window* window;
	float totalTime;
	float updateCoinCycle;
	float currentCoinTime;
	Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile);
	Texture2D loadTextureFromFile(const char *file, bool alpha);

public:
	Game();
	void setGameMode(unsigned int mode);
	void Draw();
	bool DetectCollision(Entity* entity1, Entity* entity2);
	bool FallBack(Entity*);
	void SpawnCoin(float);
	void MoveCoin();
	void CollectCoin(Coin*);
	void DropCoin(Coin*);
	void DeleteCoins(vector<int>&);
	void GameLoop();
	void PauseGame();
};