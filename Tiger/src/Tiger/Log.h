#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>

namespace Tiger {

	class TIGER_API Log
	{
	public:
		Log();
		~Log();

		static void init();

		inline static Ref<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static Ref<spdlog::logger>& getAppLogger() { return clientLogger; }
		
	private:
		static Ref<spdlog::logger> coreLogger;
		static Ref<spdlog::logger> clientLogger;
	};

}

#define TG_TRACE(...)		Tiger::Log::getCoreLogger()->trace(__VA_ARGS__);
#define TG_INFO(...)		Tiger::Log::getCoreLogger()->info(__VA_ARGS__);
#define TG_WARN(...)		Tiger::Log::getCoreLogger()->warn(__VA_ARGS__);
#define TG_ERROR(...)		Tiger::Log::getCoreLogger()->error(__VA_ARGS__);
#define TG_CRITICAL(...)	Tiger::Log::getCoreLogger()->critical(__VA_ARGS__);

#define APP_WARN(...)		Tiger::Log::getAppLogger()->warn(__VA_ARGS__);
#define APP_INFO(...)		Tiger::Log::getAppLogger()->info(__VA_ARGS__);
#define APP_WARN(...)		Tiger::Log::getAppLogger()->warn(__VA_ARGS__);
#define APP_ERROR(...)		Tiger::Log::getAppLogger()->error(__VA_ARGS__);
#define APP_CRITICAL(...)	Tiger::Log::getAppLogger()->critical(__VA_ARGS__);

