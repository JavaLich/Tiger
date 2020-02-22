#pragma once

#include "Buffer.h"

namespace Tiger {

	class VertexArray {
	public:
		virtual void addVertexBuffer(const Ref<VertexBuffer>& buffer) = 0;
		virtual void setIndexBuffer(const Ref<IndexBuffer>& buffer) = 0;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		virtual uint32_t getCount();
		
		static Ref<VertexArray> create();	
	protected:
		std::vector<Ref<VertexBuffer>> vertBuffers;
		Ref<IndexBuffer> indexBuffer;
	};

}