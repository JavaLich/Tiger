#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

#ifdef TG_PLATFORM_WINDOWS

extern Tiger::Application* Tiger::createApplication();

int main(int argc, char** argv) {
	Tiger::Log::init();

	auto app = Tiger::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif