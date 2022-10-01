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
	char* filename3;
	Player* player;
	vector<Coin*> coins;
public:
	Game();
	void setGameMode(unsigned int mode);
	void onKeyPressed(unsigned char key, int x, int y);
	void onMouseClicked(int button, int state, int x, int y);
	void onMouseMove(int x, int y);
	void timer(void(*t)(int));
	void Draw();
	bool DetectCollision(Entity* entity1, Entity* entity2);
	void SpawnCoin();
	void MoveCoin();
	void PushBack(Entity* entity1, Entity* entity2);
};