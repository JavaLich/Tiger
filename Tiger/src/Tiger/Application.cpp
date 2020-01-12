#include "Application.h"
namespace Tiger {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		static int y = 0;
		while (true) {
			y++;
			if (y % 1000000000 == 0) {
				MouseEvent event(y, y);
				Dispatcher d = Dispatcher(event);
				d.dispatch<MouseEvent>(std::bind(&Application::onEvent, this, std::placeholders::_1));
			}
		}
	}
	bool Application::onEvent(MouseEvent& event)
	{
		TG_INFO("Event: {0}", event.getX());
		return true;
	}
}