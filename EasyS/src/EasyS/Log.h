#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace Easy
{
	class EASY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define EZ_CORE_TRACE(...) ::Easy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EZ_CORE_INFO(...) ::Easy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EZ_CORE_WARN(...) ::Easy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EZ_CORE_ERROR(...) ::Easy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EZ_CORE_CRITICAL(...) ::Easy::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define EZ_TRACE(...) ::Easy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EZ_INFO(...) ::Easy::Log::GetClientLogger()->info(__VA_ARGS__)
#define EZ_WARN(...) ::Easy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EZ_ERROR(...) ::Easy::Log::GetClientLogger()->error(__VA_ARGS__)
#define EZ_CRITICAL(...) ::Easy::Log::GetClientLogger()->critical(__VA_ARGS__)