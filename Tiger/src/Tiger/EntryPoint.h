#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

#ifdef TG_PLATFORM_WINDOWS

extern Tiger::Application* Tiger::createApplication();

int main(int argc, char** argv) {
	Tiger::Log::init();
	TG_INFO("Tiger initialized");
	auto app = Tiger::createApplication();
	APP_INFO("App initialized");
	app->run();
	delete app;
	return 0;
}

#endif