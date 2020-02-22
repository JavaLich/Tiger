#include "GameLayer.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

GameLayer::~GameLayer()
{
	TG_INFO("Game Layer shutdown");
}

void GameLayer::onAttach()
{
	vao = Tiger::VertexArray::create();
	float vertices[] = {
	 -0.5f,  -0.5f, 0.0f, /*Texture Coordinates: */ 0.0f, 0.0f, // top right
	 0.5f, -0.5f, 0.0f, /*Texture Coordinates: */ 1.0f, 0.0f, // bottom right
	0.5f, 0.5f, 0.0f, /*Texture Coordinates: */ 1.0f, 1.0f, // bottom left
	-0.5f,  0.5f, 0.0f, /*Texture Coordinates: */ 0.0f, 1.0f // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 2,   // first triangle
		2, 3, 0    // second triangle
	};
	
	vao->addVertexBuffer(Tiger::VertexBuffer::create(vertices, sizeof(vertices), {
		{Tiger::VertexBuffer::Type::Float, 3}, {Tiger::VertexBuffer::Type::Float, 2}
		}));
	vao->setIndexBuffer(Tiger::IndexBuffer::create(indices, sizeof(indices)));
	shader = Tiger::Shader::create({ {Tiger::Shader::ShaderType::VertexShader, "assets/vertex.glsl"}, {Tiger::Shader::ShaderType::FragmentShader, "assets/fragment.glsl"} });
	Tiger::RenderCommand::setViewport(0, 0, 1280, 720);
	Tiger::RenderCommand::setClearColor({ 1.0f, 0.0f, 1.0f, 1.0f });
	texture = Tiger::Texture::create({ "assets/textures/awesomeface.png" });
}

void GameLayer::onDetach()
{
}

glm::vec2 offset = glm::vec2(0.0f);

void GameLayer::onUpdate()
{
	Tiger::RenderCommand::clear();
	shader->bind();
	texture->bind();
	shader->setInt("Sampler", 0);
	shader->unbind();
	Tiger::Renderer::submit(shader, vao);
}

void GameLayer::onEvent(Tiger::Event& event)
{
}

void GameLayer::onDebugGUIRender()
{
	
}
