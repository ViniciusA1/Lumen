#pragma once

#include <string>
#include <vector>

namespace Lumen
{

enum class LogLevel
{
    Info,
    Warning,
    Error
};

struct LogMessage
{
    LogLevel Level;
    std::string Message;

    LogMessage(LogLevel level, std::string message)
        : Level(level), Message(std::move(message))
    {
    }
};

class Log
{
public:
    static void Init();

    static void Clear();
    static std::vector<LogMessage> &GetLogs();

private:
    static void LogCallback(int logType, const char *text, va_list args);

private:
    static std::vector<LogMessage> s_Logs;
};

} // namespace Lumen