#pragma once

#include "Tiger/Core.h"

namespace Tiger {

	enum EventType {
		EVENT_TYPE_APPLICATION = BIT(0),
		EVENT_TYPE_WINDOW = BIT(1),
		EVENT_TYPE_KEYBOARD = BIT(2),
		EVENT_TYPE_MOUSE = BIT(3),
		EVENT_TYPE_GAMEPLAY = BIT(4)
	};

	enum EventID {
		EVENT_MOUSE_MOVED
	};
	
	class TIGER_API Event
	{
	public:
		Event();
		~Event();
		int getType() const { return type; }	
	protected:
		int type;
		EventID id;
	};

}