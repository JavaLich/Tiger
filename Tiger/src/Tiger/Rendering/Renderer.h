#pragma once

#include "RenderAPI.h"
#include "Shader.h"

namespace Tiger {

	class Renderer {

	public:
		virtual ~Renderer() = default;

		static void init();
		static void submit(Ref<Shader>& shader, Ref<VertexArray>& vertexArray);
		static void shutdown();
		
		static RenderAPI::API getAPI() { return RenderAPI::getAPI(); }
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