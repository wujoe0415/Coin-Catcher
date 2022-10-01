#include "Coin.h"
#include <GLFW/glfw3.h>

Coin::Coin(float width, float height, char* textureLocation, float moveSpeed, float rotationSpeed, float coin_damage) :Entity(width, height, textureLocation) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	setPositionX(getPositionX());
	setPositionY(getPositionY());

	angle = 0;
	move_speed = moveSpeed;
	mRotationSpeed = rotationSpeed;
	damage = coin_damage;
}
void Coin::Draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	sprite->Draw();
	glPopMatrix();
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