#include "VertexArray.h"

#include "Renderer.h"

#include "Tiger/Platform/OpenGL/GLVertexArray.h"

namespace Tiger {



	Ref<VertexArray> VertexArray::create()
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLVertexArray>();
		}
		return Ref<VertexArray>();
	}

}