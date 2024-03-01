#pragma once

#ifdef EZ_PLATFORM_WINDOWS
	#ifdef EZ_BUILD_DLL
		#define EASY_API __declspec(dllexport)
	#else
		#define EASY_API __declspec(dllimport)
	#endif
#else
	#error Only Windows Supported
#endif

#ifdef EZ_ENABLE_ASSERTS
	#define EZ_ASSERT(x, ...) { if(!(x)) { EZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EZ_CORE_ASSERT(x, ...) { if(!(x)) { EZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EZ_ASSERT(x, ...)
	#define EZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)