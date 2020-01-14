#pragma once

#include "Tiger/Core.h"

#include "Event.h"

namespace Tiger {
	
	class TIGER_API KeyEvent : public Tiger::Event {
	public:
		KeyEvent(int keyCode) : keyCode(keyCode) {}
		virtual ~KeyEvent() {}

		int getKeyCode() const { return keyCode; }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_PRESSED)
	private:
		int keyCode;
	};

	class TIGER_API KeyPressedEvent : public Tiger::KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeat) : KeyEvent(keyCode), repeat(repeat) {}
		~KeyPressedEvent() {}

		int getRepeat() const { return repeat; }
		virtual std::string toString() const override{ "KeyPressedEvent: (" + std::to_string(getKeyCode()) + "), Repeat: " + std::to_string(repeat); }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_PRESSED)
	private:
		int repeat;
	};

	class TIGER_API KeyReleasedEvent : public Tiger::KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
		~KeyReleasedEvent() {}

		virtual std::string toString() const override { "KeyReleasedEvent: (" + std::to_string(getKeyCode()) + ")"; }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_RELEASED)
	private:
	};

}