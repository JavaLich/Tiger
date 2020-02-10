#include "Input.h"

#include "Platform/Windows/WinInput.h"

namespace Tiger {

	std::unique_ptr<Input> Input::instance;

	void Input::initializeInput()
	{
#ifdef TG_PLATFORM_WINDOWS
		instance = std::make_unique<WinInput>();
#else
		TG_ERROR("Tiger only supports Windows hmm");
#endif
	}

}