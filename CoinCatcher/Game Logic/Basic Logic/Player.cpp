#include "Player.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Player::Player(float width, float height, std::string textureName,std::string shaderName, float moveSpeed, int playerHealth) : Entity(width, height, textureName, shaderName) {
	//sprite = new Sprite(width, height, textureName, shaderName);
	x = 50;
	y = 50;
	angle = 0;
	health = playerHealth;
	setHealth(health);
	move_speed = moveSpeed;

	sprite->UpdatePosition(x, y);
	InputCreater();
}
void Player::setHealth(int health) {
	this->health = health;
}

int Player::getHealth() {
	return health;
}

void Player::Draw(SpriteRenderer& Renderer) {
	sprite->Draw(Renderer);
}

void Player::MoveLeft() {
	if (x - move_speed <= 0)
		return;
	x -= move_speed; 
	setPositionX(getPositionX());
}

void Player::MoveRight() {
	if (x + move_speed  + width >= Window::getInstance().getWindowWidth())
		return;
	x += move_speed;	
	setPositionX(getPositionX());
}
void Player::InputCreater() {
	inputList.push_back(GLFW_KEY_LEFT);
	inputList.push_back(GLFW_KEY_A);
	inputList.push_back(GLFW_KEY_RIGHT);
	inputList.push_back(GLFW_KEY_D);

	Input = new KeyInput(inputList);
}
void Player::InputHandler() {
	if (Input->getIsKeyDown(GLFW_KEY_LEFT) || Input->getIsKeyDown(GLFW_KEY_A))
		MoveLeft();
	else if (Input->getIsKeyDown(GLFW_KEY_RIGHT) || Input->getIsKeyDown(GLFW_KEY_D))
		MoveRight();
}