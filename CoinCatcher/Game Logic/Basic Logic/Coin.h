#pragma once
#include "Entity.h"

class Coin : public Entity {
public:
	float move_speed;
	int damage;

	Coin(float, float, std::string, std::string, float, float, int);
	~Coin() {};
	void Draw(SpriteRenderer&);
	void MoveDown();
	void MoveUp();
	void Rotation();
	//virtual void Update();
protected:
	float mRotationSpeed;
};