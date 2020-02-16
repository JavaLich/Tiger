#include "GameLayer.h"



GameLayer::~GameLayer()
{
	TG_INFO("Game Layer shutdown");
}

void GameLayer::onAttach()
{
	vao = Tiger::VertexArray::create();
	float vertices[9] = { -0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f };
	buffer = Tiger::VertexBuffer::create(vertices, sizeof(vertices), {
		{Tiger::VertexBuffer::Type::Float, 3}
		});
	vao->addVertexBuffer(buffer);
	shader = Tiger::Shader::create({ {Tiger::Shader::ShaderType::VertexShader, "assets/vertex.glsl"}, {Tiger::Shader::ShaderType::FragmentShader, "assets/fragment.glsl"} });
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
