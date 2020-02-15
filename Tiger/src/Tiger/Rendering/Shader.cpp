#include "Shader.h"

#include "Renderer.h"

#include "Tiger/Platform/OpenGL/GLShader.h"

namespace Tiger {

	void ShaderManager::add(const std::string& name, const Ref<Shader>& shader)
	{
		shaders.insert({ name, shader });
	}

	void ShaderManager::load(const std::string& name, std::vector<Shader::ShaderStage> stages)
	{
		Ref<Shader> shader = Shader::create(stages);
		shaders.insert({ name, shader });
	}

	Ref<Shader> ShaderManager::get(const std::string& name)
	{
		return shaders[name];
	}

	Ref<Shader> Shader::create(std::vector<ShaderStage> shaders)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLShader>(shaders);
		}
		TG_ASSERT(false, "Unsupported renderering API");

		return Ref<Shader>();
	}

}