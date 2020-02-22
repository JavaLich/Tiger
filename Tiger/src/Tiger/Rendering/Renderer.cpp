#include "Renderer.h"

namespace Tiger {

	Scope<RenderAPI> RenderCommand::renderAPI = RenderAPI::create();

	void Renderer::init()
	{
		RenderCommand::init();
	}

	void Renderer::submit(Ref<Shader>& shader, Ref<VertexArray>& vertexArray)
	{
		shader->bind();
		vertexArray->bind();
		RenderCommand::render(vertexArray);
		vertexArray->unbind();
		shader->unbind();
	}

	void Renderer::shutdown()
	{
		TG_INFO("Renderer shutdown");
	}

}