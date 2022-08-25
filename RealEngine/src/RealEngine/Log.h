#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace RealEngine
{

	class RE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}


// Define helpful macros to make logging easier
// Notes: (...) means the macro can take multiple number of arguments, and __VA_ARGS__ passes in all those arguments into the function

// Core Log macros
#define RE_CORE_INFO(...)   ::RealEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_TRACE(...)  ::RealEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_CORE_WARN(...)   ::RealEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)  ::RealEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_FATAL(...)  ::RealEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
										  
// Client Log macros					  
#define RE_INFO(...)        ::RealEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define RE_TRACE(...)       ::RealEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RE_WARN(...)        ::RealEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)       ::RealEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define RE_FATAL(...)       ::RealEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)