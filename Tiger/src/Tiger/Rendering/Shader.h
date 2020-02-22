#pragma once

#include <fstream>
#include <sstream>

#include <glm/glm.hpp>

namespace Tiger {

	class Shader {
	public:
		enum class ShaderType {
			VertexShader,
			FragmentShader
		};

		struct ShaderStage {
			ShaderType type;
			std::string filepath;
			std::string src;
			ShaderStage(ShaderType t, std::string f) : type(t), filepath(f), src("") {
				std::string content;
				std::ifstream fileStream;

				fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

				try {
					fileStream.open(filepath);
					std::stringstream strStream;
					strStream << fileStream.rdbuf();
					fileStream.close();
					src = strStream.str();
				}
				catch (std::ifstream::failure e) {
					TG_ASSERT(false, "Error reading shader file");
				}
			}
		};

	public:
		virtual void compile(std::vector<ShaderStage> shaders) = 0;
		virtual void bind() = 0;
		virtual void unbind() = 0;

		virtual void setVec4(std::string location, glm::vec4 value) const = 0;
		virtual void setInt(std::string location, int value) const = 0;
		virtual void setVec2(std::string location, glm::vec2 value) const = 0;

		static Ref<Shader> create(std::initializer_list<ShaderStage> list);	
	};

	class ShaderManager {
	public:
		void add(const std::string& name, const Ref<Shader>& shader);
		void load(const std::string& name, std::initializer_list<Shader::ShaderStage> list);
		Ref<Shader> get(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader>> shaders;
	};

}