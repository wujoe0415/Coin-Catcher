#include "UI.h"
#include "System/Window.h"

UI::UI() {
	InitRender();
	NumberLoad(FirstBit);
	NumberLoad(SecondBit);
	NumberLoad(ThirdBit);
	NumberLoad(TimerFirstBit);
	NumberLoad(TimerSecondBit);
	LoadGameUI();
	FinishUI = new WholeUI(960 * 4, 960*2, "FinishUI", "standard");
}
void UI::LoadGameUI() {
	for (auto& bit : ThirdBit)
	{
		bit->setPositionX(820);
		bit->setPositionY(850);
	}
	for (auto& bit : SecondBit)
	{
		bit->setPositionX(860);
		bit->setPositionY(850);
	}
	for (auto& bit : FirstBit)
	{
		bit->setPositionX(900);
		bit->setPositionY(850);
	}
	for (auto& bit : TimerSecondBit)
	{
		bit->setPositionX(20);
		bit->setPositionY(850);
	}
	for (auto& bit : TimerFirstBit)
	{
		bit->setPositionX(60);
		bit->setPositionY(850);
	}
}
void UI::Draw(SpriteRenderer& Renderer, int score, float timer) {
	int first = (score % 10);
	score /= 10;
	int second = (score % 10);
	score /= 10;
	int third = (score % 10);

	FirstBit[first]->Draw(Renderer);
	SecondBit[second]->Draw(Renderer);
	ThirdBit[third]->Draw(Renderer);

	timer = timer < 0 ? 0: timer;
	int temp = (int)timer;
	first = temp % 10;
	second = temp / 10;
	TimerFirstBit[first]->Draw(Renderer);
	TimerSecondBit[second]->Draw(Renderer);
}

void UI::DrawEndUI(SpriteRenderer& Renderer, int score) {
	int first = (score % 10);
	score /= 10;
	int second = (score % 10);
	score /= 10;
	int third = (score % 10);

	ThirdBit[third]->setPositionX(400);
	ThirdBit[third]->setPositionY(520);
	SecondBit[second]->setPositionX(430);
	SecondBit[second]->setPositionY(520);
	FirstBit[first]->setPositionX(460);
	FirstBit[first]->setPositionY(520);
	FinishUI->setPositionX(0);
	FinishUI->setPositionY(0);
	FinishUI->Draw(Renderer);
	FirstBit[first]->Draw(Renderer);
	SecondBit[second]->Draw(Renderer);
	ThirdBit[third]->Draw(Renderer);
}

void UI::InitRender() {
	ResourceManager::LoadTexture("Resources/zero.png", true, "zero");
	ResourceManager::LoadTexture("Resources/one.png", true, "one");
	ResourceManager::LoadTexture("Resources/two.png", true, "two");
	ResourceManager::LoadTexture("Resources/three.png", true, "three");
	ResourceManager::LoadTexture("Resources/four.png", true, "four");
	ResourceManager::LoadTexture("Resources/five.png", true, "five");
	ResourceManager::LoadTexture("Resources/six.png", true, "six");
	ResourceManager::LoadTexture("Resources/seven.png", true, "seven");
	ResourceManager::LoadTexture("Resources/eight.png", true, "eight");
	ResourceManager::LoadTexture("Resources/nine.png", true, "nine");
	ResourceManager::LoadTexture("Resources/FinishUI.png", true, "FinishUI");
}

void UI::NumberLoad(vector<Entity*>& vec) {
	vec.push_back(new Number(50, 50, "zero", "standard"));
	vec.push_back(new Number(29, 50, "one", "standard"));
	vec.push_back(new Number(27, 39, "two", "standard"));
	vec.push_back(new Number(29.9, 43, "three", "standard"));
	vec.push_back(new Number(62.5, 50, "four", "standard"));
	vec.push_back(new Number(50, 50, "five", "standard"));
	vec.push_back(new Number(29.9, 43, "six", "standard"));
	vec.push_back(new Number(50, 50, "seven", "standard"));
	vec.push_back(new Number(50, 50, "eight", "standard"));
	vec.push_back(new Number(50, 50, "nine", "standard"));
}