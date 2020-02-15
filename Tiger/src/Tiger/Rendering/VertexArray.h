#pragma once

#include "Buffer.h"

namespace Tiger {

	class VertexArray {
	public:
		virtual void addVertexBuffer(const Ref<VertexBuffer>& buffer) = 0;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		
		static Ref<VertexArray> create();		
	};

}