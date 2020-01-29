#include "Application.h"


namespace Tiger {
	Application::Application()
	{
		window = Window::createWindow();
		window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
		shutdown();
	}

	void Application::run()
	{
		while (running) {
			window->onUpdate();
		}
	}

	void Application::onEvent(Event& event)
	{
		TG_INFO("Event: {0}", event.toString());
		if (event.getID() == EventID::EVENT_WINDOW_CLOSED) {
			shutdown();
		}
	}
	void Application::shutdown()
	{
		window->shutdown();
		running = false;
	}
}