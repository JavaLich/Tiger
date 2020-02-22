#pragma once

#include <glad/glad.h>

#include "Tiger/Rendering/Texture.h"

namespace Tiger {

	class GLTexture : public Texture {
	public:
		GLTexture(Texture::TextureData data);
		~GLTexture();

		virtual void bind(int unit = 0) const override;
		virtual void unbind() const override;
	private:
		GLuint id;
	};

}