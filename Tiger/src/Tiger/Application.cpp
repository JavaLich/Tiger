#include "Application.h"

#include "Rendering/Renderer.h"

namespace Tiger {

	Application* Application::instance = nullptr;

	Application::Application()
	{
		TG_ASSERT(!instance, "Application instance already initialized");
		instance = this;

		window = Window::createWindow();
		window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

		Input::initializeInput();

		Renderer::init();

		guiLayer = new GUILayer();
		stack.pushOverlay(guiLayer);
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (running) {
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
		shutdown();
	}

	void Application::onEvent(Event& event)
	{
		Dispatcher dispatcher = Dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		dispatcher.dispatch<WindowResizedEvent>(std::bind(&Application::onWindowResize, this, std::placeholders::_1));

		for (auto i = stack.rbegin(); i != stack.rend(); i++) {
			if (event.handled) break;
			(*i)->onEvent(event);
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		running = false;
		return true;
	}

	bool Application::onWindowResize(WindowResizedEvent& event)
	{
		RenderCommand::setViewport(0, 0, event.getWidth(), event.getHeight());
		return true;
	}

	void Application::shutdown()
	{
		stack.shutdown();
		window->shutdown();
		Renderer::shutdown();
		TG_INFO("Application shutdown");
	}

}