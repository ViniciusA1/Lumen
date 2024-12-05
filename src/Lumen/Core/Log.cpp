#include "Lumen/Core/Log.hpp"
#include "raylib.h"
#include <array>

namespace Lumen
{

std::unordered_map<LogLevel, std::vector<std::string>> Log::s_Logs;

void Log::Init()
{
    SetTraceLogCallback(LogCallback);
}

std::unordered_map<LogLevel, std::vector<std::string>> &Log::GetLogs()
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
    case LOG_INFO:
        level = LogLevel::Info;
        break;
    case LOG_WARNING:
        level = LogLevel::Warning;
        break;
    case LOG_ERROR:
        level = LogLevel::Error;
        break;
    default:
        level = LogLevel::Info;
        break;
    }

    s_Logs[level].emplace_back(buffer.data());
}

} // namespace Lumen