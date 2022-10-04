#include "Player.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Player::Player(float width, float height, std::string textureLocation, float moveSpeed, int playerHealth) : Entity(width, height, textureLocation) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	angle = 0;
	health = playerHealth;
	setHealth(health);
	move_speed = moveSpeed;
	//InputCreater();
}
void Player::setHealth(int health) {
	this->health = health;
}

int Player::getHealth() {
	return health;
}

void Player::Draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	sprite->Draw();
	glPopMatrix();
}

void Player::MoveLeft() {
	x -= move_speed;
}

void Player::MoveRight() {
	x += move_speed;
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
//void Player::Update() {
	
//}