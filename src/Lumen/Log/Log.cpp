#include "Lumen/Log/Log.hpp"

#include "raylib.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <array>

namespace Lumen
{

Ref<spdlog::logger> Log::s_CoreLogger;
Ref<spdlog::logger> Log::s_ClientLogger;
std::map<LogLevel, std::map<std::string, unsigned long>> Log::s_Logs;

void Log::Init()
{
    SetTraceLogCallback(LogCallback);

    auto consoleSink = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = CreateRef<spdlog::logger>("CORE", consoleSink);
    spdlog::register_logger(s_CoreLogger);
    s_CoreLogger->set_level(spdlog::level::info);
    s_CoreLogger->flush_on(spdlog::level::info);

    s_ClientLogger = CreateRef<spdlog::logger>("APP", consoleSink);
    spdlog::register_logger(s_ClientLogger);
    s_ClientLogger->set_level(spdlog::level::info);
    s_ClientLogger->flush_on(spdlog::level::info);
}

Ref<spdlog::logger> &Log::GetClientLogger()
{
    return s_ClientLogger;
}

Ref<spdlog::logger> &Log::GetCoreLogger()
{
    return s_CoreLogger;
}

std::map<LogLevel, std::map<std::string, unsigned long>> &Log::GetLogs()
{
    return s_Logs;
}

void Log::Clear()
{
    s_Logs.clear();
}

void Log::LogCallback(int logType, const char *text, va_list args)
{
    std::array<char, 512> buffer;
    vsnprintf(buffer.data(), sizeof(buffer), text, args);

    LogLevel level;
    switch (logType)
    {
    case LOG_TRACE:
        level = LogLevel::Trace;
        LM_CORE_TRACE(buffer.data());
        break;
    case LOG_INFO:
        level = LogLevel::Info;
        LM_CORE_INFO(buffer.data());
        break;
    case LOG_WARNING:
        level = LogLevel::Warn;
        LM_CORE_WARN(buffer.data());
        break;
    case LOG_ERROR:
        level = LogLevel::Error;
        LM_CORE_ERROR(buffer.data());
        break;
    case LOG_FATAL:
        level = LogLevel::Critical;
        LM_CORE_CRITICAL(buffer.data());
        break;
    default:
        level = LogLevel::Info;
        LM_CORE_INFO(buffer.data());
        break;
    }

    auto &stringMap = s_Logs[level];
    auto it = stringMap.find(buffer.data());
    if (it != stringMap.end())
        it->second++;
    else
        stringMap[buffer.data()] = 1;
}

} // namespace Lumen