#pragma once
#include "Entity.h"
#include "Number.h"
#include "WholeUI.h"
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
	WholeUI* FinishUI;
	void Draw(SpriteRenderer& renderer, int score, float timer);
	void DrawEndUI(SpriteRenderer& renderer, int score);
	void LoadGameUI();
private:
	void InitRender();
	void NumberLoad(vector<Entity*>&);
};