#include "GLBuffer.h"

namespace Tiger {
	GLVertexBuffer::GLVertexBuffer(float* vertices, uint32_t size, std::initializer_list<Attribute> list)
	{
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		setAttributes(list);
	}

	GLVertexBuffer::~GLVertexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void GLVertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void GLVertexBuffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLIndexBuffer::GLIndexBuffer(uint32_t* indices, uint32_t size) {
		count = size / sizeof(uint32_t);
		glGenBuffers(1, &id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

	GLIndexBuffer::~GLIndexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void GLIndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void GLIndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

}