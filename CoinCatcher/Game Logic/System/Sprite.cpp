#include "Sprite.h"
#include <iostream>

Sprite::Sprite(float x, float y, float width, float height, std::string textureName, std::string shaderName)
	: x(x), y(y), width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;

	mTexture = ResourceManager::GetTexture(textureName);
	mShader = ResourceManager::GetShader(shaderName);
}

Sprite::Sprite(float width, float height, std::string textureName, std::string shaderName)
	: width(width), height(height), textureName(textureName), shaderName(shaderName) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;

	mTexture = ResourceManager::GetTexture(textureName);
	std::cout << mTexture.Width << " ||| " << mTexture.Height << std::endl;
	mShader = ResourceManager::GetShader(shaderName);
}

Sprite::~Sprite() {}

void Sprite::Draw(SpriteRenderer& Renderer, float spriteX, float spriteY) {
	if (Window::getInstance().getWindowWidth() == 0 || Window::getInstance().getWindowHeight() == 0)
		return;
	spriteX = -1 + spriteX / (float)Window::getInstance().getWindowWidth();
	spriteY = -1 + spriteY / (float)Window::getInstance().getWindowHeight();
	std::cout << spriteX << " "<<spriteY<<std::endl;
	Renderer.DrawSprite(mTexture, glm::vec2(spriteX, spriteY), glm::vec2(1, 1), angle, glm::vec3(1, 1, 1));
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