#pragma once

#include "Tiger/Core.h"

#include "Event.h"

namespace Tiger {

	class TIGER_API WindowResizedEvent : public Tiger::Event {
	public:
		WindowResizedEvent(int width, int height) : width(width), height(height) {}
		~WindowResizedEvent() = default;
		
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline virtual std::string toString() const override { return "WindowResizedEvent: (" + std::to_string(width) + ", " + std::to_string(height) + ")"; }
		EVENT_TYPE(EVENT_TYPE_WINDOW)
		EVENT_ID(EventID::EVENT_WINDOW_RESIZED)
	private:
		int width, height;
	};

	class TIGER_API WindowCloseEvent : public Tiger::Event {
	public:
		WindowCloseEvent() = default;
		~WindowCloseEvent() = default;

		inline virtual std::string toString() const override { return "WindowCloseEvent"; }
		EVENT_TYPE(EVENT_TYPE_WINDOW)
		EVENT_ID(EventID::EVENT_WINDOW_CLOSED)
	};

}