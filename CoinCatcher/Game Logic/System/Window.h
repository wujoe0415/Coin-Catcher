#pragma once
#include <GLFW/glfw3.h>

class Window{
public:
	static Window& getInstance();

	static GLFWwindow* sWindow;
	void CreateWindow(int, int);
	void DestroyWindow();
	void ResizeWindow(int, int);
	int getWindowWidth();
	int getWindowHeight();

private:
	Window();
};