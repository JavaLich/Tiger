#pragma once

#include <glad/glad.h>

#include "Tiger/Rendering/Shader.h"

namespace Tiger {
	class GLShader : public Shader {
	public:
		GLShader(std::initializer_list<ShaderStage> list);
		~GLShader();

		virtual void compile(std::vector<ShaderStage> shaders) override;
		virtual void bind() override;
		virtual void unbind() override;

		virtual void setVec4(std::string location, glm::vec4 value) const override;
		virtual void setVec2(std::string location, glm::vec2 value) const override;
		virtual void setInt(std::string location, int value) const override;
		virtual void setMat4(std::string location, glm::mat4 value) const override;
	private:
		GLuint id;
	};
}