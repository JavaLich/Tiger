#pragma once

#include "Tiger/Core.h"
#include "Tiger/Log.h"

#include <functional>

#define EVENT_TYPE(x) virtual int getType() const override { return x; } \
static int getStaticType() { return x; }

#define EVENT_ID(x) virtual EventID getID() const override { return x; }

namespace Tiger {

	enum EventType {
		EVENT_TYPE_APPLICATION = BIT(0),
		EVENT_TYPE_WINDOW = BIT(1),
		EVENT_TYPE_KEYBOARD = BIT(2),
		EVENT_TYPE_MOUSE = BIT(3),
		EVENT_TYPE_GAMEPLAY = BIT(4)
	};
	
	enum class EventID {
		EVENT_MOUSE_MOVED
	};
	
	
	class TIGER_API Event
	{
	public:
		Event();
		~Event();
		virtual int getType() const = 0;
		virtual EventID getID() const = 0;	
		bool handled = false;

	};

	class TIGER_API Dispatcher {
	public:
		Dispatcher(Event& event) : event(event) {}

		template<typename T>
		bool dispatch(std::function<bool(T&)> f) {
			if (event.getType() == T::getStaticType()) {
				event.handled=f(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};


}