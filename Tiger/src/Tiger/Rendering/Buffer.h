#pragma once

#include <glm/glm.hpp>

namespace Tiger {

	class VertexBuffer {
	public:
		enum class Type {
			Float,
			Int
		};

		uint16_t getTypeSize(Type type, uint16_t count) {
			switch (type) {
			case(Type::Float):
				return count * 4;
			case(Type::Int):
				return count * 4;
			}
			TG_ASSERT(false, "Type doesn't exist");
			return 0;
		}

		struct Attribute {
			uint16_t offset;

			Attribute() = default;
			Attribute(Type type, uint16_t count, bool normalized = false, uint16_t offset = 0) : type(type), count(count), normalized(normalized), offset(offset) {}

			uint16_t count;
			Type type;
			bool normalized;
		};

	public:
		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		void setAttributes(std::initializer_list<Attribute> list);
		inline uint32_t getStride() const { return stride; }
		inline std::vector<Attribute> getAttributes() const { return attributes; }

		static Ref<VertexBuffer> create(float* vertices, uint32_t size, std::initializer_list<Attribute> list);
	private:
		void calculateStridesAndOffsets();
	private:
		uint32_t stride;
	protected:
		std::vector<Attribute> attributes;
	};

	class IndexBuffer {
	public:
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		virtual uint32_t getCount();

		static Ref<IndexBuffer> create(uint32_t* indices, uint32_t size);
	protected:
		uint32_t count;
	};

}