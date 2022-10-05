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
}

Sprite::~Sprite() {}

void Sprite::Draw(SpriteRenderer& Renderer) {
	std::cout << x << " " << y << std::endl;
	Renderer.DrawSprite(mTexture, glm::vec2(x, y), glm::vec2(1, 1), angle, glm::vec3(0, 1, 0));
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