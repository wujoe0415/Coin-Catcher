#include "Sprite.h"
#include <iostream>

Sprite::Sprite(float x, float y, float width, float height, std::string textureName, std::string shaderName)
	: x(x), y(y), width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;

	mTexture = ResourceManager::GetTexture(textureName);
	mShader = ResourceManager::GetShader(shaderName);
	textureHeight = mTexture.Height;
	textureWidth = mTexture.Width;
}

Sprite::Sprite(float width, float height, std::string textureName, std::string shaderName)
	: width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;

	mTexture = ResourceManager::GetTexture(textureName);
	mShader = ResourceManager::GetShader(shaderName);
	textureHeight = mTexture.Height;
	textureWidth = mTexture.Width;
}

Sprite::~Sprite() {}

void Sprite::Draw(SpriteRenderer& Renderer) {
	if (Window::getInstance().getWindowWidth() == 0 || Window::getInstance().getWindowHeight() == 0)
		return;
	float spriteX = -1 + x / (float)Window::getInstance().getWindowWidth() * 2;
	float spriteY = -1 + y / (float)Window::getInstance().getWindowHeight() * 2;

	Renderer.DrawSprite(mTexture, glm::vec2(spriteX, spriteY), glm::vec2(width/textureWidth, height/textureHeight), angle, glm::vec3(1, 1, 1));
}
void Sprite::UpdatePosition(float newx, float newy)
{
	x = newx;
	y = newy;
}
void Sprite::setAngle(float angle) {
	this->angle = angle;
}

float Sprite::getAngle() {
	return angle;
}