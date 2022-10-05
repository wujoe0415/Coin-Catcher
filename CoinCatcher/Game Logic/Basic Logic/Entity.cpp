#include "Entity.h"
#include <iostream>

Entity::Entity(float width, float height, std::string textureName, std::string shaderName)
	: width(width), height(height){

	sprite = new Sprite(width, height, textureName, shaderName);
	x = 100;
	y = 100;
	angle = 0;
}

float Entity::getPositionX() {
	return x;
}

float Entity::getPositionY() {
	return y;
}

void Entity::setPositionX(float x) {
	this->x = x;
	sprite->UpdatePosition(x, y);
}

void Entity::setPositionY(float y) {
	this->y = y;
	sprite->UpdatePosition(x, y);
}

float Entity::getWidth() {
	return width;
}

float Entity::getHeight() {
	return height;
}

void Entity::setAngle(float angle) {
	this->angle = angle;
	sprite->setAngle(angle);
}

float Entity::getAngle() {
	return angle;
}