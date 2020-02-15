#include "GameLayer.h"



void GameLayer::onAttach()
{
	vao = Tiger::VertexArray::create();
	float vertices[9] = { -0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f };
	buffer = Tiger::VertexBuffer::create(vertices, sizeof(vertices));
	std::vector<Tiger::VertexBuffer::Attribute> attributes = {
		{Tiger::VertexBuffer::Type::Float, 3}
	};
	buffer->setAttributes(attributes);
	vao->addVertexBuffer(buffer);
	std::vector<Tiger::Shader::ShaderStage> stages = { {Tiger::Shader::ShaderType::VertexShader, "assets/vertex.glsl"}, {Tiger::Shader::ShaderType::FragmentShader, "assets/fragment.glsl"} };
	shader = Tiger::Shader::create(stages);
	Tiger::RenderCommand::setViewport(0, 0, 1280, 720);
}

void GameLayer::onDetach()
{
}

void GameLayer::onUpdate()
{
	Tiger::RenderCommand::setClearColor({ 1.0f, 0.0f, 1.0f, 1.0f });
	Tiger::RenderCommand::clear();

	Tiger::Renderer::submit(shader, vao);
}

void GameLayer::onEvent(Tiger::Event& event)
{
}

void GameLayer::onDebugGUIRender()
{
}
