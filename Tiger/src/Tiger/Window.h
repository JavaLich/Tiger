#pragma once

#include "Core.h"

#include "Events/MouseEvent.h"
#include "Events/AppEvent.h"
#include "Events/KeyEvent.h"

namespace Tiger {
	class TIGER_API Window {
	public:
		std::function<void(Event&)> eventCallback;

		virtual ~Window() = default;
		virtual void destroyWindow() = 0;
		virtual void terminate() = 0;
		virtual void shutdown() = 0;

		virtual void init(const char* title, int width, int height) = 0;

		virtual void setSize(int width, int height) = 0;
		virtual void setPosition(int x, int y) = 0;
		virtual void setTitle(const char* title) = 0;
		inline void setEventCallback(std::function<void(Event&)> cb) { eventCallback = cb; }

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual int getXPos() const = 0;
		virtual int getYPos() const = 0;

		virtual void toggleFullscreen() = 0;
		virtual void toggleVsync() = 0;

		virtual void onUpdate() = 0;
		virtual void* getNativeWindow() = 0;

		static std::unique_ptr<Window> createWindow(const char* title = "Tiger Engine", int width = 1280, int height = 720);		
	};
}