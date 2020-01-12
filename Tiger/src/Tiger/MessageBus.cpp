#include "MessageBus.h"

#include "Log.h"

namespace Tiger {

	std::vector<Event> MessageBus::mouseEvents;

	Tiger::MessageBus::MessageBus()
	{
		mouseEvents = std::vector<Event>();
		mouseEvents.reserve(MAX_MOUSE_EVENTS);
	}

	Tiger::MessageBus::~MessageBus()
	{
	}
	
	void Tiger::MessageBus::handleMessage(const Event& event)
	{
		switch (event.getType()) {
			case(EVENT_TYPE_MOUSE):
				mouseEvents.emplace_back(event);
		}
	}

}
