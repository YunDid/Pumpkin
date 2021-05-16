#pragma once

#ifdef PK_PLATFORM_WINDOWS

	#ifdef PK_BUILD_DLL
		#define PUMPKIN_API __declspec(dllexport)
	#else
		#define PUMPKIN_API __declspec(dllimport)
	#endif

#else
	#error Sorry! Pumpkin only supports Windows!

#endif