#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include "System/Window.h"
#include <iostream>
#include "System/KeyInput.h"
#include "Basic Logic/Game.h"

void CloseWindow()
{
	glfwSetWindowShouldClose(Window::getInstance().sWindow, GLFW_TRUE);
}

int main(void)
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;
	
	Window* window = &Window::getInstance();
	window->CreateWindow(1280, 960);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Game* CoinCatcher = new Game();
	//CoinCatcher->setGameMode(1);

	vector<int> inputList{ GLFW_KEY_ESCAPE };
	KeyInput* keyinputs = new KeyInput(inputList);
	// Initialize Input callback
	KeyInput::setupKeyInputs(*window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window->sWindow))
	{
		if (keyinputs->getIsKeyDown(GLFW_KEY_ESCAPE))
			CloseWindow();

		// calculate delta time

		CoinCatcher->GameLoop();

		/* Poll for and process events */
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT);
		/* Swap front and back buffers */
	
		CoinCatcher->Draw();
		glfwSwapBuffers(window->sWindow);

	}
	glfwTerminate();
	return 0;
}