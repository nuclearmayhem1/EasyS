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
