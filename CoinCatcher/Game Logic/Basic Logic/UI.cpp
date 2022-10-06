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
	FinishUI = new WholeUI(0, 0, "FinishUI", "standard");
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

	ThirdBit[third]->setPositionX(500);
	ThirdBit[third]->setPositionY(500);
	SecondBit[second]->setPositionX(530);
	SecondBit[second]->setPositionY(500);
	FirstBit[first]->setPositionX(560);
	FirstBit[first]->setPositionY(500);

	FinishUI->Draw(Renderer);
	FirstBit[first]->Draw(Renderer);
	SecondBit[second]->Draw(Renderer);
	ThirdBit[third]->Draw(Renderer);
}

void UI::InitRender() {
	ResourceManager::LoadTexture("zero.png", true, "zero");
	ResourceManager::LoadTexture("one.png", true, "one");
	ResourceManager::LoadTexture("two.png", true, "two");
	ResourceManager::LoadTexture("three.png", true, "three");
	ResourceManager::LoadTexture("four.png", true, "four");
	ResourceManager::LoadTexture("five.png", true, "five");
	ResourceManager::LoadTexture("six.png", true, "six");
	ResourceManager::LoadTexture("seven.png", true, "seven");
	ResourceManager::LoadTexture("eight.png", true, "eight");
	ResourceManager::LoadTexture("nine.png", true, "nine");
	ResourceManager::LoadTexture("FinishUI.png", true, "FinishUI");
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