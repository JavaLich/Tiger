#include "RenderAPI.h"

#include "Tiger/Platform/OpenGL/GLRenderAPI.h"

namespace Tiger {

	RenderAPI::API RenderAPI::api = RenderAPI::API::OpenGL;

	Scope<RenderAPI> RenderAPI::create()
	{
		switch (api) {
		case(API::OpenGL):
			return MakeScope<GLRenderAPI>();
		}
		TG_ASSERT(false, "Unsupported rendering API");
		return Scope<RenderAPI>();
	}

}