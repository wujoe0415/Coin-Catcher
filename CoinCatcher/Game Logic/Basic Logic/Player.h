#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	float health;
	float move_speed;
	Player(float, float, char*, float, float);
	~Player() {};
	void Draw();
	void MoveRight();
	void MoveLeft();
	void setHealth(float);
	float getHealth();
};