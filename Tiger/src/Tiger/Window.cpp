#include "Window.h"
#include "Platform/Windows/WinWindow.h"

namespace Tiger {
	Scope<Window> Window::createWindow(const char* title, int width, int height)
	{
#ifdef TG_PLATFORM_WINDOWS
		return MakeScope<WinWindow>(title, width, height);
#endif 
		TG_ERROR("Tiger only supports Windows");
		return nullptr;
	}
}