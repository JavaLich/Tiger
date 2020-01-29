#pragma once

#include "Tiger/Core.h"

#include "Event.h"

namespace Tiger {

	class TIGER_API MouseEvent : public Tiger::Event
	{
	public:
		MouseEvent(double x, double y) : x(x), y(y) {}
		~MouseEvent() = default;
		inline double getX() const { return x; }
		inline double getY() const { return y; }

		EVENT_TYPE(EVENT_TYPE_MOUSE);
		EVENT_ID(EventID::EVENT_MOUSE_MOVED);
		virtual std::string toString() const { return "MouseEvent: (" + std::to_string(x) + ", " + std::to_string(y) + ")"; }
	private:
		double x, y;
	};

	class TIGER_API MouseMovedEvent : public Tiger::MouseEvent
	{
	public:
		MouseMovedEvent(double x, double y) : MouseEvent(x, y) {}
		~MouseMovedEvent() = default;

		EVENT_TYPE(EVENT_TYPE_MOUSE);
		EVENT_ID(EventID::EVENT_MOUSE_MOVED);
		virtual std::string toString() const { return "MouseMovedEvent: (" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")"; }
	};

	class TIGER_API MousePressedEvent : public Tiger::MouseEvent
	{
	public:
		MousePressedEvent(double x, double y, int button) : MouseEvent(x, y), button(button) {}
		~MousePressedEvent() = default;

		inline int getButton() const { return button; }

		EVENT_TYPE(EVENT_TYPE_MOUSE);
		EVENT_ID(EventID::EVENT_MOUSE_PRESSED);
		virtual std::string toString() const { return "MousePressedEvent: (" + std::to_string(getX()) + ", " + std::to_string(getY()) + "), Button: "+std::to_string(button); }
	private:
		int button;
	};

	class TIGER_API MouseReleasedEvent : public Tiger::MouseEvent
	{
	public:
		MouseReleasedEvent(double x, double y, int button) : MouseEvent(x, y), button(button) {}
		~MouseReleasedEvent() = default;

		inline int getButton() const { return button; }

		EVENT_TYPE(EVENT_TYPE_MOUSE);
		EVENT_ID(EventID::EVENT_MOUSE_RELEASED);
		virtual std::string toString() const { return "MouseRelasedEvent: (" + std::to_string(getX()) + ", " + std::to_string(getY()) + "), Button: " + std::to_string(button); }
	private:
		int button;
	};
}
