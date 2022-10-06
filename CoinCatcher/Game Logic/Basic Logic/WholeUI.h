#pragma once
#include "Entity.h"

class WholeUI : public Entity {
public:
	WholeUI(float, float, std::string, std::string);
	~WholeUI() {};
	void Draw(SpriteRenderer&);
};