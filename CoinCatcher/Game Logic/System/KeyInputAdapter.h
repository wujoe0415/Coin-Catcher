#pragma once
#include "KeyInput.h"
#include <vector>

class KeyInputAdapter
{
public:
	KeyInputAdapter();
	std::vector<int> inputList;
	KeyInput* Input;
	virtual void InputCreater() = 0;
	virtual void InputHandler() = 0;
};