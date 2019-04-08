#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace KRYT {


	class KRYT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_Core_Logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_Client_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Core_Logger;
		static std::shared_ptr<spdlog::logger> s_Client_Logger;
	};

}

//Core Log Macros
#define KR_CORE_TRACE(...)	::KRYT::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KR_CORE_INFO(...)	::KRYT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KR_CORE_WARN(...)	::KRYT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KR_CORE_ERROR(...)	::KRYT::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KR_CORE_FATAL(...)	::KRYT::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define KR_TRACE(...)		::KRYT::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KR_INFO(...)		::KRYT::Log::GetClientLogger()->info(__VA_ARGS__)
#define KR_WARN(...)		::KRYT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KR_ERROR(...)		::KRYT::Log::GetClientLogger()->error(__VA_ARGS__)
#define KR_FATAL(...)		::KRYT::Log::GetClientLogger()->fatal(__VA_ARGS__)