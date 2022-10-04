#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "System/Window.h"
#include <iostream>
//#include "System/KeyInput.h"
//#include "Basic Logic/Game.h"

//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//	if (key == GLFW_KEY_ESCAPE || action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//}

int main(void)
{
	Window* window = &Window::getInstance();
	window->CreateWindow(1280, 960);

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	//Game* CoinCatcher = new Game();
	//CoinCatcher->setGameMode(1);

	// Initialize Input callback
	//KeyInput::setupKeyInputs(*window);

	glfwMakeContextCurrent(window->sWindow);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window->sWindow))
	{
		/* Render here */
		glClearColor(0.0f, 1.f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		/* Swap front and back buffers */
		glfwSwapBuffers(window->sWindow);
		/* Poll for and process events */
		glfwPollEvents();

		//CoinCatcher->GameLoop();
	}
	glfwTerminate();
	return 0;
}