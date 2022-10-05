#pragma once
#include "Entity.h"
#include "Number.h"
#include <vector>

using namespace std;

class UI{
public:
	UI();
	vector<Entity*> FirstBit;
	vector<Entity*> SecondBit;
	vector<Entity*> ThirdBit;
	void Draw(SpriteRenderer&, int);

private:
	void InitRender();
};
