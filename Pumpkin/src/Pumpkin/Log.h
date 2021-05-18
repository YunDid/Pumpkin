#pragma once

#include<memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Pumpkin {

	class PUMPKIN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core Log macros 
#define PK_CORE_TRACE(...)			::Pumpkin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PK_CORE_INFO(...)			::Pumpkin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PK_CORE_WARN(...)			::Pumpkin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PK_CORE_ERROR(...)			::Pumpkin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PK_CORE_FATAL(...)			::Pumpkin::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros 
#define PK_CLIENT_TRACE(...)		::Pumpkin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PK_CLIENT_INFO(...)			::Pumpkin::Log::GetClientLogger()->info(__VA_ARGS__)
#define PK_CLIENT_WARN(...)			::Pumpkin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PK_CLIENT_ERROR(...)		::Pumpkin::Log::GetClientLogger()->error(__VA_ARGS__)
#define PK_CLIENT_FATAL(...)		::Pumpkin::Log::GetClientLogger()->fatal(__VA_ARGS__)

