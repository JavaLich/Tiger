#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/MouseEvent.h"

namespace Tiger {
	class TIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		/*
		Make window instance
		Window instance has its own function pointer and event callback
		set window function pointer to onEvent
		use dispatcher to dispatch event with function pointer
		*/
		std::unique_ptr<Window> window;
		void onEvent(Event& event);
		void shutdown();
	private:
		bool running = true;
	};

	Application* createApplication();
}
