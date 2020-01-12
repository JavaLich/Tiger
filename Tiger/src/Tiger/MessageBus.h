#pragma once

#define MAX_MOUSE_EVENTS 5

#include "Core.h"
#include "Events/Event.h"

#include <vector>

namespace Tiger {

	class TIGER_API MessageBus
	{
	public:
		MessageBus();
		~MessageBus();

		static void handleMessage(const Event& event);

	private:
		//Lists for each type of event 

	};

}

#define POST_EVENT(x) Tiger::MessageBus.handleMessage(x)

