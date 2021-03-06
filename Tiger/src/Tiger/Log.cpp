#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Tiger {

	
	Ref<spdlog::logger> Log::coreLogger;
	Ref<spdlog::logger> Log::clientLogger;


	Log::Log()
	{
	}

	void Log::init() {
		coreLogger = spdlog::stdout_color_mt("Tiger");
		clientLogger = spdlog::stdout_color_mt("App");
		spdlog::set_pattern("%^[%T] %n: %v%$");
		spdlog::set_level(spdlog::level::trace);
	}


	Log::~Log()
	{
	}

}