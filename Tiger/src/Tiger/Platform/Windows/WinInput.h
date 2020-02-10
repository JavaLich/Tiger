#pragma once

#include "Tiger/Input.h"

namespace Tiger {
	class WinInput : public Input {
	public:
		virtual bool isKeyPressed(KeyCode keyCode) override;
		virtual bool isMouseButtonPressed(MouseCode mouseCode) override;
		virtual std::pair<double, double> getMousePos() override;
	};
}