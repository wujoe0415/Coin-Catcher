#include "Entity.h"
#include <iostream>

Entity::Entity(float width, float height, std::string textureName, std::string shaderName)
	: width(width), height(height){

	sprite = new Sprite(width, height, textureName, shaderName);
}

float Entity::getPositionX() {
	return x;
}

float Entity::getPositionY() {
	return y;
}

void Entity::setPositionX(float x) {
	this->x = x;
	sprite->UpdatePosition(this->x, this->y);
}

void Entity::setPositionY(float y) {
	this->y = y;
	sprite->UpdatePosition(this->x, this->y);
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