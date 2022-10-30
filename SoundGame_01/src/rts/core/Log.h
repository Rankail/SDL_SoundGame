#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

class Log
{
public:
	static void Init();
	static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

private:
	static std::shared_ptr<spdlog::logger> s_Logger;
};

#define LOG_TRACE(...)         Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      Log::GetLogger()->critical(__VA_ARGS__)