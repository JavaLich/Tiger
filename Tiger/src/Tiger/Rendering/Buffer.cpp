#include "Buffer.h"

#include "Renderer.h"
#include "Tiger/Platform/OpenGL/GLBuffer.h"

namespace Tiger {

	void VertexBuffer::setAttributes(std::initializer_list<Attribute> list)
	{
		this->attributes = list;
		calculateStridesAndOffsets();
	}

	Ref<VertexBuffer> VertexBuffer::create(float* vertices, uint32_t size, std::initializer_list<Attribute> list)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLVertexBuffer>(vertices, size, list);
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