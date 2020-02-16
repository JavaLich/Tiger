#include "Shader.h"

#include "Renderer.h"

#include "Tiger/Platform/OpenGL/GLShader.h"

namespace Tiger {

	void ShaderManager::add(const std::string& name, const Ref<Shader>& shader)
	{
		shaders.insert({ name, shader });
	}

	void ShaderManager::load(const std::string& name, std::initializer_list<Shader::ShaderStage> list)
	{
		Ref<Shader> shader = Shader::create(list);
		shaders.insert({ name, shader });
	}

	Ref<Shader> ShaderManager::get(const std::string& name)
	{
		return shaders[name];
	}

	Ref<Shader> Shader::create(std::initializer_list<ShaderStage> list)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLShader>(list);
		}
		TG_ASSERT(false, "Unsupported renderering API");

		return Ref<Shader>();
	}

}