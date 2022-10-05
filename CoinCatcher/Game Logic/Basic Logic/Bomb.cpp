#include "Bomb.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Bomb::Bomb(float width, float height, std::string textureName, std::string shaderName, float moveSpeed, float rotationSpeed, float damage) : Entity(width, height, textureName, shaderName) {
	//sprite = new Sprite(width, height, textureName, shaderName);
	x = 100;
	y = 960;
	setPositionX(getPositionX());
	setPositionY(getPositionY());

	angle = 0;
	move_speed = moveSpeed;
	mRotationSpeed = rotationSpeed;
	mDamage = damage;
}
void Bomb::Draw(SpriteRenderer& Renderer) {
	sprite->Draw(Renderer);
}
void Bomb::MoveDown() {
	// move_speed += gravityAcceration
	y -= move_speed;
	setPositionY(getPositionY());

	Rotation();
}
void Bomb::MoveUp()
{
	y += move_speed;
	setPositionY(getPositionY());
}
void Bomb::Rotation() {
	angle += mRotationSpeed;
	setAngle(angle);
}