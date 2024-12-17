#pragma once

#include <map>
#include <string>

namespace Lumen
{

enum class LogLevel
{
    Info,
    Warning,
    Error
};

class Log
{
public:
    static void Init();

    static std::map<LogLevel, std::map<std::string, unsigned long>> &GetLogs();

    static void Clear();

private:
    static void LogCallback(int logType, const char *text, va_list args);

private:
    static std::map<LogLevel, std::map<std::string, unsigned long>> s_Logs;
};

} // namespace Lumen