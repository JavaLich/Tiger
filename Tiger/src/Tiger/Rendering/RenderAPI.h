#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Tiger {

	class RenderAPI {
	public:
		enum class API {
			None, OpenGL, DX12, Vulkan
		};

		virtual void init() = 0;
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void setClearColor(const glm::vec4 color) = 0;
		virtual void clear() = 0;

		virtual void render(const Ref<VertexArray> vertexArray) = 0;

		static API getAPI() { return api; }

		static Scope<RenderAPI> create();
	private:
		static API api;
	};

}