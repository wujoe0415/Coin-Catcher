#pragma once
#include "KeyInput.h"
#include <vector>

class KeyInputAdapter {
public:
	vector<int> inputList;
	KeyInput* Input;
	virtual void InputCreater() = 0;
	virtual void InputHandler() = 0;
};