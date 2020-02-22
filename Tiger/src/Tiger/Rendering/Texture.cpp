#include "Texture.h"

#include "Tiger/Platform/OpenGL/GLTexture.h"

#include "Renderer.h"

namespace Tiger {

	void Texture::freeData()
	{
		stbi_image_free(data.data);
	}

	Ref<Texture> Texture::create(TextureData texData)
	{
		switch (Renderer::getAPI()) {
		case(RenderAPI::API::OpenGL):
			return MakeRef<GLTexture>(texData);
		}

		TG_ERROR("Unsupported rendering API");

		return Ref<Texture>();
	}

}
