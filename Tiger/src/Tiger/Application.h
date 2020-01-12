#pragma once

#include "Core.h"
#include "Log.h"
#include "Events/MouseEvent.h"

namespace Tiger {
	class TIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		bool onEvent(MouseEvent& event);
		
	};

	Application* createApplication();
}
