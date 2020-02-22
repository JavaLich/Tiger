#pragma once

#include <glad/glad.h>

#include "Tiger/Rendering/Buffer.h"

namespace Tiger {

	class GLVertexBuffer : public VertexBuffer {
	public:
		GLVertexBuffer(float* vertices, uint32_t num, std::initializer_list<Attribute> list);
		~GLVertexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;
	private:
		GLuint id;
	};

	class GLIndexBuffer : public IndexBuffer {
	public:
		GLIndexBuffer(uint32_t* indices, uint32_t size);
		~GLIndexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;
	private:
		GLuint id;
	};

}