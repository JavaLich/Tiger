#include "GLContext.h"

namespace Tiger {

	void GLContext::init()
	{
		glfwMakeContextCurrent(window);

		TG_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Glad failed to initalize");
	}

	void GLContext::swapBuffers()
	{
		glfwSwapBuffers(window);
	}

}