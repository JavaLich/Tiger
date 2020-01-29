#include "WinWindow.h"

namespace Tiger {

	bool WinWindow::glfwInitialized = false;

	Tiger::WinWindow::WinWindow(const char* title, int width, int height)
	{
		init(title, width, height);
	}

	Tiger::WinWindow::~WinWindow()
	{
		shutdown();
	}

	void Tiger::WinWindow::destroyWindow()
	{
		glfwDestroyWindow(window);
	}

	void WinWindow::terminate()
	{
		glfwTerminate();
	}

	void WinWindow::shutdown()
	{
		destroyWindow();
		terminate();
	}

	void WinWindow::init(const char* title, int width, int height)
	{
		if (!WinWindow::glfwInitialized) {
			TG_ASSERT(glfwInit(), "GLFW failed to initialize");
		}
		glfwWindowHint(GLFW_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_VERSION_MINOR, 5);
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		TG_ASSERT(window, "GLFW failed to create window");
		glfwSetWindowUserPointer(window, this);

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS) {
				KeyPressedEvent event(key);
				static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				KeyReleasedEvent event(key);
				static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
			}
			else if (action == GLFW_REPEAT) {
				KeyPressedEvent event(key, 1);
				static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
			}
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			WindowCloseEvent event;
			static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
		});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			WindowResizedEvent event(width, height);
			static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y) {
			MouseMovedEvent event(x, y);
			static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			double x, y;
			glfwGetCursorPos(window, &x, &y);
			if (action == GLFW_PRESS) {
				MousePressedEvent event(x, y, button);
				static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				MouseReleasedEvent event(x, y, button);
				static_cast<WinWindow*>(glfwGetWindowUserPointer(window))->eventCallback(event);
			}
		});

		glfwMakeContextCurrent(window);
	}

	void Tiger::WinWindow::setSize(int width, int height)
	{
		glfwSetWindowSize(window, width, height);
	}

	void Tiger::WinWindow::setPosition(int x, int y)
	{
		glfwSetWindowPos(window, x, y);
	}

	void Tiger::WinWindow::setTitle(const char* title)
	{
		glfwSetWindowTitle(window, title);
	}

	int Tiger::WinWindow::getWidth() const
	{
		int width = 0;
		glfwGetWindowSize(window, &width, nullptr);
		return width;
	}

	int Tiger::WinWindow::getHeight() const
	{
		int height = 0;
		glfwGetWindowSize(window, nullptr, &height);
		return height;
	}

	int WinWindow::getXPos() const
	{
		int xpos = 0;
		glfwGetWindowPos(window, &xpos, nullptr);
		return xpos;
	}

	int WinWindow::getYPos() const
	{
		int ypos = 0;
		glfwGetWindowPos(window, nullptr, &ypos);
		return ypos;
	}

	void WinWindow::toggleFullscreen()
	{
		if(glfwGetWindowMonitor(window)==NULL)
			glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), getXPos(), getYPos(), getWidth(), getHeight(), GLFW_DONT_CARE);
		else
			glfwSetWindowMonitor(window, NULL, getXPos(), getYPos(), getWidth(), getHeight(), GLFW_DONT_CARE);
	}

	void WinWindow::toggleVsync()
	{
		if (!vsync) {
			vsync = true;
			glfwSwapInterval(1);
		}
		else {
			vsync = false;
			glfwSwapInterval(0);
		}
	}

	void WinWindow::onUpdate()
	{

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void* WinWindow::getNativeWindow()
	{
		return window;
	}

}