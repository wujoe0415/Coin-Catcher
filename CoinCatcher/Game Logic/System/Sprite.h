#pragma once

#include "IDrawable.h"
#include <glad/glad.h>
#include <System/Sprite_Renderer.h>
#include "System/Resource_Manager.h"
#include "System/Shader.h"
#include "System/Window.h"

class Sprite {
private:
	float x, y;
	float width, height;
	float origoX, origoY;
	float angle;
	//GLuint textureName;
	Texture2D   mTexture;
	Shader mShader;

public:
	Sprite(float, float, float, float, std::string, std::string);
	Sprite(float, float, std::string, std::string);
	~Sprite();
	void Draw(SpriteRenderer&, float, float);
	void UpdatePosition(float, float);
	void setAngle(float);
	float getAngle();
	std::string textureName;
	std::string shaderName;
};