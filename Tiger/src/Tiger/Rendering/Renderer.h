#pragma once

#include "RenderAPI.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"

namespace Tiger {

	class Renderer {
	public:

		struct RenderState {
			glm::mat4 viewProj = glm::mat4(1.0f);
		};
	
	public:
		virtual ~Renderer() = default;

		static void init();
		static void begin(PerspectiveCamera& camera);
		static void end();
		static void submit(Ref<Shader>& shader, Ref<VertexArray>& vertexArray, glm::mat4 transform = glm::mat4(1.0f));
		static void shutdown();
		
		static RenderAPI::API getAPI() { return RenderAPI::getAPI(); }

	private:
		static Scope<RenderState> state;
	};

	class RenderCommand {
	public:

		inline static void init() {
			renderAPI->init();
		}

		inline static void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
			renderAPI->setViewport(x, y, width, height);
		}

		inline static void setClearColor(const glm::vec4& color) {
			renderAPI->setClearColor(color);
		}

		inline static void clear() {
			renderAPI->clear();
		}
		
		inline static void render(Ref<VertexArray> vertexArray) {
			renderAPI->render(vertexArray);
		}

	private:
		static Scope<RenderAPI> renderAPI;
	};

}