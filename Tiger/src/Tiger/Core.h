#pragma once

#ifdef TG_PLATFORM_WINDOWS
	#ifdef TG_STATIC
		#define TIGER_API
	#elif defined(TG_BUILD_DLL)
		#define TIGER_API _declspec(dllexport)
	#else
		#define TIGER_API _declspec(dllimport)
	#endif
#else #error Tiger only supports windows
#endif

#define BIT(x) 1 << x

#ifdef TG_DEBUG
	#define ENABLE_ASSERTS
#endif

#ifdef ENABLE_ASSERTS
	#define TG_ASSERT(x, ...) {if(!x) {TG_ERROR("Assertion: {0}", __VA_ARGS__); __debugbreak();}}  
	#define APP_ASSERT(x, ...) {if(!x) {APP_ERROR("Assertion: {0}", __VA_ARGS__); __debugbreak();}}
#elif
	#define TG_ASSERT(x, ...) 
	#define APP_ASSERT(x, ...) 
#endif 