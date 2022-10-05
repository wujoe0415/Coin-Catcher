#include "UI.h"

UI::UI() {
	InitRender();
	FirstBit.push_back(new Number(50, 50, "zero", "standard"));
	SecondBit.push_back(new Number(50, 50, "zero", "standard"));
	ThirdBit.push_back(new Number(50, 50, "zero", "standard"));

	FirstBit.push_back(new Number(50, 50, "one", "standard"));
	SecondBit.push_back(new Number(50, 50, "one", "standard"));
	ThirdBit.push_back(new Number(50, 50, "one", "standard"));

	FirstBit.push_back(new Number(50, 50, "two", "standard"));
	SecondBit.push_back(new Number(50, 50, "two", "standard"));
	ThirdBit.push_back(new Number(50, 50, "two", "standard"));

	FirstBit.push_back(new Number(50, 50, "three", "standard"));
	SecondBit.push_back(new Number(50, 50, "three", "standard"));
	ThirdBit.push_back(new Number(50, 50, "three", "standard"));

	FirstBit.push_back(new Number(50, 50, "four", "standard"));
	SecondBit.push_back(new Number(50, 50, "four", "standard"));
	ThirdBit.push_back(new Number(50, 50, "four", "standard"));

	FirstBit.push_back(new Number(50, 50, "five", "standard"));
	SecondBit.push_back(new Number(50, 50, "five", "standard"));
	ThirdBit.push_back(new Number(50, 50, "five", "standard"));

	FirstBit.push_back(new Number(50, 50, "six", "standard"));
	SecondBit.push_back(new Number(50, 50, "six", "standard"));
	ThirdBit.push_back(new Number(50, 50, "six", "standard"));

	FirstBit.push_back(new Number(50, 50, "seven", "standard"));
	SecondBit.push_back(new Number(50, 50, "seven", "standard"));
	ThirdBit.push_back(new Number(50, 50, "seven", "standard"));

	FirstBit.push_back(new Number(50, 50, "eight", "standard"));
	SecondBit.push_back(new Number(50, 50, "eight", "standard"));
	ThirdBit.push_back(new Number(50, 50, "eight", "standard"));

	FirstBit.push_back(new Number(50, 50, "nine", "standard"));
	SecondBit.push_back(new Number(50, 50, "nine", "standard"));
	ThirdBit.push_back(new Number(50, 50, "nine", "standard"));

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
};

void UI::Draw(SpriteRenderer& Renderer, int score) {
	int first = (score % 10);
	score /= 10;
	int second = (score % 10);
	score /= 10;
	int third = (score % 10);

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
}