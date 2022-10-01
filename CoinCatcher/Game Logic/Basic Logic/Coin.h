#pragma once
#include "Entity.h"

class Coin : public Entity {
public:
	float move_speed;
	float damage;

	Coin(float, float, char*, float, float, float);
	~Coin() {};
	void Draw();
	void MoveDown();
	void MoveUp();
	void Rotation();
protected:
	float mRotationSpeed;
};