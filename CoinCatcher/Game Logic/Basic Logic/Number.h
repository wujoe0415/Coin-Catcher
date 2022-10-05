#pragma once
#include "Entity.h"

class Number : public Entity {
public :
	Number(float, float, std::string, std::string);
	~Number() {};
	void Draw(SpriteRenderer&);
};