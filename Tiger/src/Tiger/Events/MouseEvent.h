#pragma once

#include "../Core.h"

#include "Event.h"

namespace Tiger {
	class TIGER_API MouseEvent : public Tiger::Event
	{
	public:
		MouseEvent(int x, int y) : x(x), y(y) {
			type = EVENT_TYPE_MOUSE | EVENT_TYPE_APPLICATION;
			id = EVENT_MOUSE_MOVED;
		}
		~MouseEvent();
		
		int getX() { return x; }
		int getY() { return y; }
	protected:
		int x, y;
	};
}
