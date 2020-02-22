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
		
		for (auto it = attributes.begin(); it != attributes.end(); ++it) {
			(*it).offset = currentOffset;
			currentOffset += getTypeSize((*it).type, (*it).count);
		}

		stride = currentOffset;
	}

	uint32_t IndexBuffer::getCount()
	{
		return count;
	}

	Ref<IndexBuffer> IndexBuffer::create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLIndexBuffer>(indices, size);
		}

		TG_ASSERT(false, "Unsupported rendering API");
		return Ref<IndexBuffer>();
	}

}