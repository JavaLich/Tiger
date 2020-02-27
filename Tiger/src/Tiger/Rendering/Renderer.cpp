#include "Renderer.h"

namespace Tiger {

	Scope<RenderAPI> RenderCommand::renderAPI = RenderAPI::create();
	Scope<Renderer::RenderState> Renderer::state = MakeScope<Renderer::RenderState>();

	void Renderer::init()
	{
		RenderCommand::init();
	}

	void Renderer::begin(PerspectiveCamera& camera)
	{
		//CHANGE THIS TO VIEWPROJ
		state->viewProj = camera.getViewProj();
	}

	void Renderer::end()
	{
	}

	//TODO: implement batched rendering
	//Temporary submission function
	void Renderer::submit(Ref<Shader>& shader, Ref<VertexArray>& vertexArray, glm::mat4 transform)
	{
		shader->bind();
		shader->setMat4("viewProj", state->viewProj);
		shader->setMat4("modelMatrix", transform);
		vertexArray->bind();
		RenderCommand::render(vertexArray);
	}

	void Renderer::shutdown()
	{
		TG_INFO("Renderer shutdown");
	}

}