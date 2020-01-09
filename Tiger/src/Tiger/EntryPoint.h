#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

#ifdef TG_PLATFORM_WINDOWS

extern Tiger::Application* Tiger::createApplication();

int main(int argc, char** argv) {
	Tiger::Log::init();
	TG_INFO("Logger initialized");
	Tiger::Log::getAppLogger()->info("WHY");
	auto app = Tiger::createApplication();
	app->run();
	delete app;
	return 0;
}

#endif