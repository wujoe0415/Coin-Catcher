#pragma once
#include "Entity.h"

class Ground :public Entity {
public:
	Ground(float, float, char*);
	virtual void Draw();
};