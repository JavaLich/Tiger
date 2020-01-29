#pragma once

#include "Tiger/Core.h"
#include "Tiger/Window.h"

#include <GLFW/glfw3.h>

namespace Tiger {
	class TIGER_API WinWindow : public Tiger::Window {
	public:
		WinWindow(const char* title, int width, int height);
		virtual ~WinWindow() override;
		virtual void destroyWindow() override;
		virtual void terminate() override;
		virtual void shutdown() override;

		virtual void init(const char* title, int width, int height) override;

		virtual void setSize(int width, int height) override;
		virtual void setPosition(int x, int y) override;
		virtual void setTitle(const char* title) override;

		virtual int getWidth() const override;
		virtual int getHeight() const override;
		virtual int getXPos() const override;
		virtual int getYPos() const override;

		virtual void toggleFullscreen() override;
		virtual void toggleVsync() override;

		virtual void onUpdate() override;
		virtual void* getNativeWindow() override;
	private:
		GLFWwindow* window;
		static bool glfwInitialized;
		bool vsync = false;
	};
}