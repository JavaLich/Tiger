#pragma once

#include <stb_image.h>
#include <stb_image_write.h>

namespace Tiger {

	class Texture {
	public:

		enum class FilteringModes {
			Nearest,
			Bilinear,
			Trilinear
		};

		struct TextureData {
			std::string filename;
			unsigned char* data = nullptr;
			int width = 0, height = 0, numChannels = 0;
			FilteringModes mode = FilteringModes::Trilinear;

			TextureData(std::string f, FilteringModes m = FilteringModes::Trilinear) : filename(f), mode(m) {
				stbi_set_flip_vertically_on_load(true);
				data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
			}

			TextureData() : data(nullptr), width(0), height(0), numChannels(0), mode(FilteringModes::Trilinear){
				
			}
		};

	public:
		Texture() {};

		virtual void bind(int unit = 0) const = 0;
		virtual void unbind() const = 0;

		void freeData();
		static Ref<Texture> create(TextureData texData);
	protected:
		TextureData data;
	};

}