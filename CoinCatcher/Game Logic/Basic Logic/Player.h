#pragma once
#include "Entity.h"
#include "System/KeyInput.h"

class Player : public Entity, public KeyInputAdapter{
public:
	float health;
	float move_speed;
	Player(float, float, char*, float, float);
	~Player() {};
	void Draw();
	//virtual void Update();
	void MoveRight();
	void MoveLeft();
	void setHealth(float);
	float getHealth();

	virtual void InputCreater();
	virtual void InputHandler();
};