#pragma once

#include "Application.h"

#ifdef TG_PLATFORM_WINDOWS

extern Tiger::Application* Tiger::createApplication();

int main(int argc, char** argv) {
	auto app = Tiger::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif