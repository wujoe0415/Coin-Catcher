#include "Sprite.h"
#include <iostream>

Sprite::Sprite(float x, float y, float width, float height, std::string textureName, std::string shaderName)
	: x(x), y(y), width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;
}

Sprite::Sprite(float width, float height, std::string textureName, std::string shaderName)
	: width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;

	mTexture = ResourceManager::GetTexture(textureName);
	mShader = ResourceManager::GetShader(shaderName);

	Renderer = new SpriteRenderer(mShader);
}

Sprite::~Sprite() {}


void Sprite::Draw() {
	Renderer->DrawSprite(mTexture, glm::vec2(x,y), glm::vec2(1, 1), angle, glm::vec3(0, 0 ,0));

	/*glBindTexture(GL_TEXTURE_2D, textureName);

	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);


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
	glDisable(GL_TEXTURE_2D);*/
}

void Sprite::setAngle(float angle) {
	this->angle = angle;
}

float Sprite::getAngle() {
	return angle;
}