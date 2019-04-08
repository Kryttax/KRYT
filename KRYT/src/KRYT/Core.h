#pragma once

#ifdef KR_PLATFORM_WINDOWS

#ifdef KR_BUILD_DLL
	#define KRYT_API __declspec(dllexport)
#else
	#define KRYT_API __declspec(dllimport)

#endif // KR_BUILD_DLL

#else
	#error KRYT only supports Windows
#endif // KR_PLATFORM_WINDOWS

#define BIT(x) (1 << x)