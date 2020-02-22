#include "GLVertexArray.h"

namespace Tiger {



	GLVertexArray::GLVertexArray()
	{
		glGenVertexArrays(1, &id);
	}

	GLVertexArray::~GLVertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	void GLVertexArray::addVertexBuffer(const Ref<VertexBuffer>& buffer)
	{
		vertBuffers.push_back(buffer);
		buffer->bind();
		glBindVertexArray(id);
		GLuint index = 0;
		for (VertexBuffer::Attribute attribute : buffer->getAttributes()) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, attribute.count, GL_FLOAT, attribute.normalized ? GL_TRUE : GL_FALSE, buffer->getStride(), (const void*)attribute.offset);
			index++;
		}
	}

	void GLVertexArray::setIndexBuffer(const Ref<IndexBuffer>& buffer)
	{
		indexBuffer = buffer;
		glBindVertexArray(id);
		indexBuffer->bind();
	}

	void GLVertexArray::bind() const
	{
		glBindVertexArray(id);
	}

	void GLVertexArray::unbind() const
	{
		glBindVertexArray(0);
	}

}