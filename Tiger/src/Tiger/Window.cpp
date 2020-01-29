#include "Window.h"
#include "Platform/Windows/WinWindow.h"

namespace Tiger {
	std::unique_ptr<Window> Window::createWindow(const char* title, int width, int height)
	{
#ifdef TG_PLATFORM_WINDOWS
		return std::make_unique<WinWindow>(title, width, height);
#endif 
		TG_ERROR("Tiger only supports Windows!");
		return nullptr;
	}
}