#include "Window.h"
#include "KeyInput.h"
#include <vector>

using namespace std;

int Window::getWindowHeight()
{
	int* h = 0;
	int* w = 0;

	glfwGetWindowSize(sWindow, w, h);
	return (*h);
}
int Window::getWindowWidth()
{
	int* h = 0;
	int* w = 0;

	glfwGetWindowSize(sWindow, w, h);
	return (*w);
}

void Window::DestroyWindow() {
	glfwDestroyWindow(sWindow);
	glfwTerminate();
}
void Window::CreateWindow(int width, int height) {
	/* Create a windowed mode window and its OpenGL context */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	sWindow = glfwCreateWindow(width, height, "Coin Catcher", NULL, NULL);
	if (!sWindow)
		glfwTerminate();

	glfwMakeContextCurrent(sWindow);
}
Window& Window::instance()
{
	static Window sInstance;
	return sInstance;
}

void Window::InputCreater() {
	inputList.push_back(GLFW_KEY_ESCAPE);
	Input = new KeyInput(inputList);
	//Input->setupKeyInputs(this);
}
void Window::InputHandler() {
	// repeat to check
	if(Input->getIsKeyDown(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(sWindow, GLFW_TRUE);
}
Window::Window() {
	InputCreater();
}