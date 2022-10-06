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
	vector<Entity*> TimerFirstBit;
	vector<Entity*> TimerSecondBit;
	void Draw(SpriteRenderer& renderer, int score, float timer);
private:
	void InitRender();
	void NumberLoad(vector<Entity*>&);
};