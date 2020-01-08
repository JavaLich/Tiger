#pragma once

#include "Core.h"

namespace Tiger {
	class TIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}
