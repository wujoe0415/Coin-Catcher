#include "Player.h"
#include <GLFW/glfw3.h>

Player::Player(float width, float height, char* textureLocation, float moveSpeed, float playerHealth) : Entity(width, height, textureLocation) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	angle = 0;
	health = playerHealth;
	setHealth(health);
	move_speed = moveSpeed;
}
void Player::setHealth(float health) {
	this->health = health;
}

float Player::getHealth() {
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

static void player_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_A && key == GLFW_KEY_LEFT) || action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}