#pragma once

#include "Tiger/Core.h"

#define EVENT_TYPE(x) virtual int getType() const override { return x; } \
static int getStaticType() { return x; }

#define EVENT_ID(x) virtual EventID getID() const override { return x; } static Tiger::Event::EventID getStaticID() { return x; }

namespace Tiger {
	
	class TIGER_API Event
	{
	public:

		enum EventType {
			EVENT_TYPE_APPLICATION = BIT(0),
			EVENT_TYPE_WINDOW = BIT(1),
			EVENT_TYPE_KEYBOARD = BIT(2),
			EVENT_TYPE_MOUSE = BIT(3),
			EVENT_TYPE_GAMEPLAY = BIT(4)
		};

		enum class EventID {
			EVENT_MOUSE_MOVED,
			EVENT_MOUSE_PRESSED,
			EVENT_MOUSE_RELEASED,
			EVENT_KEY_PRESSED,
			EVENT_KEY_RELEASED,
			EVENT_WINDOW_RESIZED,
			EVENT_WINDOW_CLOSED
		};

	public:
		Event() = default;
		~Event() = default;
		virtual int getType() const = 0;
		virtual EventID getID() const = 0;	
		virtual std::string toString() const = 0;
		bool handled = false;
	};

	class TIGER_API Dispatcher {
	public:
		Dispatcher(Event& event) : event(event) {}

		template<typename T>
		bool dispatch(std::function<bool(T&)> f) {
			if (event.getID() == T::getStaticID()) {
				event.handled=f(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};

	inline std::ostream & operator<<(std::ostream& str, Event const& v) {
		return str << v.toString();
	}
}