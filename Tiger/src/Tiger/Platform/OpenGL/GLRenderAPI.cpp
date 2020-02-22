#include "GLRenderAPI.h"

#include <GLFW/glfw3.h>

namespace Tiger {

	void APIENTRY glDebugOutput(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		TG_ASSERT(false, "Encountered OpenGL error");
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         TG_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       TG_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          TG_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: TG_TRACE(message); return;
		}

		TG_ASSERT(false, "Unknown severity level!");
	}

	void GLRenderAPI::init()
	{

#ifdef TG_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(glDebugOutput, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	void GLRenderAPI::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void GLRenderAPI::setClearColor(const glm::vec4 color)
	{
		glClearColor(color[0], color[1], color[2], color[3]);
	}

	void GLRenderAPI::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLRenderAPI::render(const Ref<VertexArray> vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->getCount(), GL_UNSIGNED_INT, 0);
	}

}