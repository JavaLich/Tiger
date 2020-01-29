#pragma once

#include "Tiger/Core.h"

#include "Event.h"

namespace Tiger {
	
	class TIGER_API KeyEvent : public Tiger::Event {
	public:
		KeyEvent(int keyCode) : keyCode(keyCode) {}
		~KeyEvent() = default;

		inline int getKeyCode() const { return keyCode; }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_PRESSED)
	private:
		int keyCode;
	};

	class TIGER_API KeyPressedEvent : public Tiger::KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeat = 0) : KeyEvent(keyCode), repeat(repeat) {}
		~KeyPressedEvent() = default;

		inline int getRepeat() const { return repeat; }
		inline virtual std::string toString() const override{ return "KeyPressedEvent: (" + std::to_string(getKeyCode()) + "), Repeat: " + std::to_string(repeat); }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_PRESSED)
	private:
		int repeat;
	};

	class TIGER_API KeyReleasedEvent : public Tiger::KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
		~KeyReleasedEvent() = default;

		inline virtual std::string toString() const override { return "KeyReleasedEvent: (" + std::to_string(getKeyCode()) + ")"; }
		EVENT_TYPE(EVENT_TYPE_KEYBOARD)
		EVENT_ID(EventID::EVENT_KEY_RELEASED)
	private:
	};

}