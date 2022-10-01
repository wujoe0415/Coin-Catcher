#pragma once
#include <GLFW/glfw3.h>
#include "KeyInputAdapter.h"

class Window : public KeyInputAdapter{
public:
	static Window& instance();

	static GLFWwindow* sWindow;
	void CreateWindow(int, int);
	void DestroyWindow();
	void ResizeWindow(int, int);
	int getWindowWidth();
	int getWindowHeight();

	virtual void InputCreater();
	virtual void InputHandler();

private:
	Window();
};