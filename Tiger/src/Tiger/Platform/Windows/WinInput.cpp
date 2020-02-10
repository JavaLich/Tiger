#include "WinInput.h"

#include "Tiger/Application.h"

#include <GLFW/glfw3.h>

namespace Tiger {

	bool WinInput::isKeyPressed(KeyCode keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keyCode);

		return state == GLFW_PRESS;
	}

	bool WinInput::isMouseButtonPressed(MouseCode mouseCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, mouseCode);

		return state == GLFW_PRESS;
	}

	std::pair<double, double> WinInput::getMousePos()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { x, y };
	}

}