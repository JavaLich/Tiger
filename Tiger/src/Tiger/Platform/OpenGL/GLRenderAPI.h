#pragma once

#include <glad/glad.h>

#include "Tiger/Rendering/RenderAPI.h"

namespace Tiger {

	class GLRenderAPI : public RenderAPI {
		virtual void init() override;
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void setClearColor(const glm::vec4 color) override;
		virtual void clear() override;

		virtual void render(const Ref<VertexArray> vertexArray) override;
	};

}