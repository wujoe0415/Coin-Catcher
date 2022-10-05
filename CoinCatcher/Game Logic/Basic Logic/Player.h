#pragma once
#include "Entity.h"
#include "System/KeyInput.h"

class Player : public Entity{
public:
	int health;
	float move_speed;
	Player(float, float, std::string, std::string, float, int);
	~Player() {};
	void Draw();
	//virtual void Update();
	void MoveRight();
	void MoveLeft();
	void setHealth(int);
	int getHealth();

	KeyInput* Input;
	vector<int> inputList;
	void InputHandler();
	void InputCreater();
};