#include "GLTexture.h"

namespace Tiger {

	GLTexture::GLTexture(Texture::TextureData data)
	{
		TG_ASSERT(data.data, "Texture failed to load");
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		switch (data.mode) {
		case(Texture::FilteringModes::Nearest):
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		case(Texture::FilteringModes::Bilinear):
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		case(Texture::FilteringModes::Trilinear):
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		if (data.numChannels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, data.width, data.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data);
		else if (data.numChannels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, data.width, data.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data.data);
		else
			TG_ERROR("Unsupported texture format for file: {0}", data.filename);

		glGenerateMipmap(GL_TEXTURE_2D);

		freeData();
	}

	GLTexture::~GLTexture()
	{
		glDeleteTextures(1, &id);
	}

	void GLTexture::bind(int unit) const
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void GLTexture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}