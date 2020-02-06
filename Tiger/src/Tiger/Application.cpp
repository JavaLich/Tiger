#include "Application.h"

#include "glad/glad.h"
namespace Tiger {

	Application* Application::instance = nullptr;

	Application::Application()
	{
		TG_ASSERT(!instance, "Application instance already initialized");
		instance = this;

		window = Window::createWindow();
		window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

		guiLayer = new GUILayer();
		stack.pushOverlay(guiLayer);
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (running) {
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (Layer* layer : stack) {
				layer->onUpdate();
			}

			guiLayer->startRender();
			for (Layer* layer : stack) {
				layer->onDebugGUIRender();
			}
			guiLayer->endRender();
			
			window->onUpdate();
		}
	}

	void Application::onEvent(Event& event)
	{
		if (event.getID() == EventID::EVENT_WINDOW_CLOSED) {
			shutdown();
		}
	}
	void Application::shutdown()
	{
		stack.shutdown();
		window->shutdown();
		running = false;
		TG_INFO("Application shutdown");
	}

}