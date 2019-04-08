#include "KRpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace KRYT {

	std::shared_ptr<spdlog::logger> Log::s_Core_Logger;
	std::shared_ptr<spdlog::logger> Log::s_Client_Logger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n:  %v%$");
		s_Core_Logger = spdlog::stdout_color_mt("KRYT");
		s_Core_Logger->set_level(spdlog::level::trace);
		
		s_Client_Logger = spdlog::stdout_color_mt("APP");
		s_Client_Logger->set_level(spdlog::level::trace);
	}
}
