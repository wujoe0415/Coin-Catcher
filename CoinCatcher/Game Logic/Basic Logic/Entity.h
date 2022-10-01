#pragma once
#include "IDrawable.h"
#include "Sprite.h"

class Entity : public IDrawable {
protected:
	float x, y;
	float width, height;
	float angle;
	Sprite* sprite;
public:
	Entity(float, float, char*);
	virtual float getPositionX();
	virtual float getPositionY();
	virtual void setPositionX(float);
	virtual void setPositionY(float);
	virtual float getWidth();
	virtual float getHeight();
	virtual void setAngle(float);
	virtual float getAngle();
	virtual void Draw() = 0;
};