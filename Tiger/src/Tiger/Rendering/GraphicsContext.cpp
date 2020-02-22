#include "GraphicsContext.h"

#include "Tiger/Rendering/Renderer.h"

#include "Tiger/Platform/OpenGL/GLContext.h"


namespace Tiger {

	Scope<GraphicsContext> Tiger::GraphicsContext::create(void* window)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeScope<GLContext>(static_cast<GLFWwindow*>(window));
		}
		TG_ASSERT(false, "Unsupported rendering API");
		return Scope<GLContext>();
	}

}
