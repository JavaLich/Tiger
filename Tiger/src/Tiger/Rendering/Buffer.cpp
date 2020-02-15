#include "Buffer.h"

#include "Renderer.h"
#include "Tiger/Platform/OpenGL/GLBuffer.h"

namespace Tiger {

	void VertexBuffer::setAttributes(std::vector<Attribute>& attributes)
	{
		this->attributes = attributes;
		calculateStridesAndOffsets();
	}

	Ref<VertexBuffer> VertexBuffer::create(float* vertices, uint32_t size)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLVertexBuffer>(vertices, size);
		}

		TG_ASSERT(false, "Unsupported rendering API");
		return Ref<VertexBuffer>();
	}

	void VertexBuffer::calculateStridesAndOffsets()
	{
		uint16_t currentOffset = 0;
		for (auto attribute : attributes) {
			attribute.offset = currentOffset;
			currentOffset += getTypeSize(attribute.type, attribute.count);
		}

		stride = currentOffset;
	}

}