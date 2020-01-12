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

