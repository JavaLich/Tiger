#include "Input.h"

#include "Platform/Windows/WinInput.h"

namespace Tiger {

	Scope<Input> Input::instance;

	void Input::initializeInput()
	{
#ifdef TG_PLATFORM_WINDOWS
		instance = MakeScope<WinInput>();
#else
		TG_ERROR("Tiger only supports Windows hmm");
#endif
	}

}