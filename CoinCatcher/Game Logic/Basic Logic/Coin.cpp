#include "Coin.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Coin::Coin(float width, float height, std::string textureName, std::string shaderName, float moveSpeed, float rotationSpeed, int coin_damage) :Entity(width, height, textureName, shaderName) {
	sprite = new Sprite(width, height, textureName, shaderName);
	x = 100;
	y = 100;
	setPositionX(getPositionX());
	setPositionY(getPositionY());

	angle = 0;
	move_speed = moveSpeed;
	mRotationSpeed = rotationSpeed;
	damage = coin_damage;
}
void Coin::Draw(SpriteRenderer& Renderer) {
	sprite->Draw(Renderer);
}
void Coin::MoveDown() {
	// move_speed += gravityAcceration
	y += move_speed;

	setPositionY(getPositionY());
}
void Coin::MoveUp()
{
	y -= move_speed;
	setPositionY(getPositionY());
}
void Coin::Rotation() {
	angle += mRotationSpeed;
	setAngle(angle);
}
//void Coin::Update() {
//
//}