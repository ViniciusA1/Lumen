#pragma once

#include "Lumen/Memory/Memory.hpp"

#include <map>
#include <spdlog/spdlog.h>
#include <string>

namespace Lumen
{

enum class LogLevel
{
    Trace,
    Info,
    Warn,
    Error,
    Critical,
};

class Log
{
public:
    static void Init();

    static Ref<spdlog::logger> &GetClientLogger();
    static Ref<spdlog::logger> &GetCoreLogger();
    static std::map<LogLevel, std::map<std::string, unsigned long>> &GetLogs();

    static void Clear();

private:
    static void LogCallback(int logType, const char *text, va_list args);

private:
    static Ref<spdlog::logger> s_CoreLogger;
    static Ref<spdlog::logger> s_ClientLogger;
    static std::map<LogLevel, std::map<std::string, unsigned long>> s_Logs;
};

} // namespace Lumen

#define LM_CORE_TRACE(...) ::Lumen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LM_CORE_INFO(...) ::Lumen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LM_CORE_WARN(...) ::Lumen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LM_CORE_ERROR(...) ::Lumen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LM_CORE_CRITICAL(...) ::Lumen::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LM_TRACE(...) ::Lumen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LM_INFO(...) ::Lumen::Log::GetClientLogger()->info(__VA_ARGS__)
#define LM_WARN(...) ::Lumen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LM_ERROR(...) ::Lumen::Log::GetClientLogger()->error(__VA_ARGS__)
#define LM_CRITICAL(...) ::Lumen::Log::GetClientLogger()->critical(__VA_ARGS__)