#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Input.h"

#include "Events/Event.h"
#include "Events/MouseEvent.h"
#include "LayerStack.h"
#include "ImGUI/GUILayer.h"

namespace Tiger {
	class TIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& event);
		bool onWindowClose(WindowCloseEvent& event);
		bool onWindowResize(WindowResizedEvent& event);
		void shutdown();
		inline static Application& get() { return *instance; }
		inline Window& getWindow() { return *window; }
		bool running = true;

		LayerStack stack;
	private:
		static Application* instance;
		Scope<Window> window;
		GUILayer* guiLayer;
	};

	Application* createApplication();
}
