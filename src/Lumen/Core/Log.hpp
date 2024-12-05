#pragma once

#include <string>
#include <unordered_map>
#include <vector>

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

    static std::unordered_map<LogLevel, std::vector<std::string>> &GetLogs();

    static void Clear();

private:
    static void LogCallback(int logType, const char *text, va_list args);

private:
    static std::unordered_map<LogLevel, std::vector<std::string>> s_Logs;
};

} // namespace Lumen