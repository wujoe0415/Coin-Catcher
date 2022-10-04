#pragma once

#include "IDrawable.h"
#include <glad/glad.h>
#include <System/Sprite_Renderer.h>
#include "System/Resource_Manager.h"

class Sprite : IDrawable {
private:
	float x, y;
	float width, height;
	float origoX, origoY;
	float angle;
	GLuint textureName;
	char* filename;
	void loadTextureFromFile(char*);
	void initTexture(char*);
	Texture2D   Texture;

public:
	Sprite(float, float, float, float, char*);
	Sprite(float, float, char*);
	~Sprite();
	void Draw();
	void setAngle(float);
	float getAngle();
};