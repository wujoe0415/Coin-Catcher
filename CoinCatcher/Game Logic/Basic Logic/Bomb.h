#pragma once
#include "Entity.h"

class Bomb : public Entity {
public:

	Bomb(float, float, std::string, std::string, float, float, float);
	~Bomb() {};
	void Draw(SpriteRenderer&);
	void MoveDown();
	void MoveUp();
	void Rotation();
	float mDamage;
	//virtual void Update();
private:
	float move_speed;
	float mRotationSpeed;
};