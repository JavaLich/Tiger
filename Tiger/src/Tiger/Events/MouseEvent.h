#pragma once

#include "Tiger/Core.h"

#include "Event.h"

namespace Tiger {
	class TIGER_API MouseEvent : public Tiger::Event
	{
	public:
		MouseEvent(int x, int y) : x(x), y(y) {}
		~MouseEvent();

		int getX() const { return x; }
		int getY() const { return y; }
		EVENT_TYPE(EVENT_TYPE_MOUSE | EVENT_TYPE_APPLICATION);
		EVENT_ID(EventID::EVENT_MOUSE_MOVED);
	protected:
		int x, y;
	};
}
