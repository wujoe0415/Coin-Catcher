#include "Sprite.h"
#include <iostream>

Sprite::Sprite(float x, float y, float width, float height, std::string filename)
	: x(x), y(y), width(width), height(height), filename(filename) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;
	initTexture(filename);
}

Sprite::Sprite(float width, float height, std::string filename)
	: width(width), height(height), filename(filename) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;
	initTexture(filename);
}

Sprite::~Sprite() {}

void Sprite::loadTextureFromFile(std::string filename) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, textureName);

	Texture = ResourceManager::GetTexture(filename);
}

void Sprite::initTexture(std::string filename) {
	glGenTextures(1, &textureName);
	glBindTexture(GL_TEXTURE_2D, textureName);
	loadTextureFromFile(filename);
}

void Sprite::Draw() {
	initTexture(filename);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, textureName);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-origoX, -origoY);
	glTexCoord2f(0.0, 1.0); glVertex2f(-origoX + width, -origoY);
	glTexCoord2f(1.0, 1.0); glVertex2f(-origoX + width, -origoY + height);
	glTexCoord2f(1.0, 0.0); glVertex2f(-origoX, -origoY + height);
	glEnd();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Sprite::setAngle(float angle) {
	this->angle = angle;
}

float Sprite::getAngle() {
	return angle;
}