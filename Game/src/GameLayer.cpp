#include "GameLayer.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

GameLayer::~GameLayer()
{
	TG_INFO("Game Layer shutdown");
}

Tiger::Ref<Tiger::VertexArray> vao;
Tiger::Ref<Tiger::Shader> shader;
Tiger::Ref<Tiger::Texture> texture;

Tiger::PerspectiveCamera cam;

glm::mat4 transform = glm::mat4(1.0f);

void GameLayer::onAttach()
{
	vao = Tiger::VertexArray::create();
	float vertices[] = {
	 -0.5f,  -0.5f, 0.0f, /*Texture Coordinates: */ 0.0f, 0.0f, 
	 0.5f, -0.5f, 0.0f, /*Texture Coordinates: */ 1.0f, 0.0f, 
	0.5f, 0.5f, 0.0f, /*Texture Coordinates: */ 1.0f, 1.0f, 
	-0.5f,  0.5f, 0.0f, /*Texture Coordinates: */ 0.0f, 1.0f 
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
glm::vec4 color = glm::vec4(1.0f);
glm::vec3 camPos = { 0.0f, 0.0f, -1.0f };

float fov = 45.0f;
float aspectRatio = 1280.0f / 720.0f;
float n = 0.1f;
float f = 100.0f;

void GameLayer::onUpdate()
{
	Tiger::RenderCommand::clear();

	shader->bind();
	texture->bind();
	shader->setInt("Sampler", 0);
	shader->setVec4("color", color);
	shader->unbind();

	Tiger::Renderer::begin(cam);
	Tiger::Renderer::submit(shader, vao);
	Tiger::Renderer::end();
}

void GameLayer::onEvent(Tiger::Event& event)
{
}

void GameLayer::onDebugGUIRender()
{
	ImGui::Begin("Game Layer");
	ImGui::ColorPicker4("Blend Color", glm::value_ptr(color));
	ImGui::SliderFloat3("Camera Position", glm::value_ptr(camPos), -1.0f, 1.0f);
	ImGui::SliderAngle("Camera FOV", &fov, 0.0f);
	ImGui::SliderFloat("Camera Aspect Ratio", &aspectRatio, 0.0f, 2.0f);
	ImGui::SliderFloat("Camera Near", &n, 0.0f, 10.0f);
	ImGui::SliderFloat("Camera Far", &f, 0.0f, 10000.0f);
	ImGui::End();
	cam.setPos(camPos);
	cam.setFOV(fov);
	cam.setAspectRatio(aspectRatio);
	cam.setClipSpace(n, f);
}
