#include <iostream>
#include "KeyInput.h"
using namespace std;

class TestInput {
public:
	TestInput() {
		InputCreater();
	}
	std::vector<int> inputList;
	KeyInput* Input;

	void InputHandler() {
		if (Input->getIsKeyDown(GLFW_KEY_LEFT))
			std::cout << "Input" << std::endl;
	}
	void InputCreater() {
		inputList.push_back(GLFW_KEY_LEFT);
		inputList.push_back(GLFW_KEY_A);
		inputList.push_back(GLFW_KEY_RIGHT);
		inputList.push_back(GLFW_KEY_D);

		Input = new KeyInput(inputList);
	}
};
void main() {
	TestInput* test = new TestInput();
	while (true) {
		test->InputHandler();
	}
}