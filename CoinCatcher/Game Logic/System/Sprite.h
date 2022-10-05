#pragma once

#include "IDrawable.h"
#include <glad/glad.h>
#include <System/Sprite_Renderer.h>
#include "System/Resource_Manager.h"
#include "System/Shader.h"

class Sprite : IDrawable {
private:
	float x, y;
	float width, height;
	float origoX, origoY;
	float angle;
	GLuint textureName;
	std::string filename;
	void loadTextureFromFile(std::string);
	void initTexture(std::string);
	Texture2D   Texture;
	Shader mShader;
	SpriteRenderer* Renderer;

public:
	Sprite(float, float, float, float, std::string);
	Sprite(float, float, std::string);
	~Sprite();
	void Draw();
	void setAngle(float);
	float getAngle();
};