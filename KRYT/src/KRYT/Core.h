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

#ifdef KR_ENABLE_ASSERTS
	#define KR_ASSERT(x, ...) {if(!x)) { KR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define KR_CORE_ASSERT(x, ...) {if(!x) {KR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define KR_ASSERT(x, ...)
	#define KR_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)