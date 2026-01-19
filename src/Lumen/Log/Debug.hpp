#pragma once

#include <string>

namespace Lumen
{

class Debug
{
public:
    Debug() = delete;

public:
    static void Assert(bool condition, const std::string &message);

    static void LogTrace(const std::string &message);
    static void LogInfo(const std::string &message);
    static void LogWarning(const std::string &message);
    static void LogError(const std::string &message);
    static void LogCritical(const std::string &message);
};

} // namespace Lumen