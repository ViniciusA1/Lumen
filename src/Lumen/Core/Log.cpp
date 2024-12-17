#include "Lumen/Core/Log.hpp"
#include "raylib.h"
#include <array>

namespace Lumen
{

std::map<LogLevel, std::map<std::string, unsigned long>> Log::s_Logs;

void Log::Init()
{
    SetTraceLogCallback(LogCallback);
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

    auto &stringMap = s_Logs[level];
    auto it = stringMap.find(buffer.data());
    if (it != stringMap.end())
    {
        it->second++;
    }
    else
    {
        stringMap[buffer.data()] = 1;
    }
}

} // namespace Lumen