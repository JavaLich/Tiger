#include "GLShader.h"

namespace Tiger {

	static GLuint getShaderType(Shader::ShaderType type) {
		switch (type) {
		case(Shader::ShaderType::VertexShader):
			return GL_VERTEX_SHADER;
		case(Shader::ShaderType::FragmentShader):
			return GL_FRAGMENT_SHADER;
		}
		TG_ASSERT(false, "Uknown shader type");
		return 0;
	}

	GLShader::GLShader(std::initializer_list<ShaderStage> list)
	{
		std::vector<ShaderStage> shaders = list;
		compile(shaders);
	}

	GLShader::~GLShader()
	{
		glDeleteProgram(id);
	}

	void GLShader::compile(std::vector<ShaderStage> shaders)
	{
		GLuint program = glCreateProgram();
		std::array<GLuint, 2> shaderIDs;
		int index = 0;
		for (ShaderStage stage : shaders) {
			GLuint type = getShaderType(stage.type);
			GLuint shader = glCreateShader(type);
			const char* src = stage.src.c_str();
			glShaderSource(shader, 1, &src, NULL);
			glCompileShader(shader);

			int success;
			char infoLog[512];
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				TG_ERROR("Shader failed to compile: {0}", infoLog);
			}
			glAttachShader(program, shader);
			shaderIDs[index++] = shader;
		}
		glLinkProgram(program);
		int success;
		char infoLog[512];
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			TG_ERROR("Shader failed to link: {0}", infoLog);
		}
		id = program;
		for (GLuint shader : shaderIDs) {
			glDeleteShader(shader);
		}
	}

	void GLShader::bind()
	{
		glUseProgram(id);
	}

	void GLShader::unbind()
	{
		glUseProgram(0);
	}

}