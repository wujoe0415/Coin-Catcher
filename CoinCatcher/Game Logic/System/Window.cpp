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
void Window::ResizeWindow(int width, int height) {
	
}
Window& Window::getInstance()
{
	static Window sInstance;
	return sInstance;
}

Window::Window() {
}

GLFWwindow* Window::sWindow;