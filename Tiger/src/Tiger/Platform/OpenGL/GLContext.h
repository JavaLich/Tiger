#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Tiger/Rendering/GraphicsContext.h"

namespace Tiger {

	class GLContext : public GraphicsContext
	{
	public:
		GLContext(GLFWwindow* window) : window(window) {
			TG_ASSERT(window, "Window handle is null");
		}

		virtual void init() override;
		virtual void swapBuffers() override;
	private:
		GLFWwindow* window;
	};
}