#pragma once

#include "Lumen/Core/Log.hpp"

namespace Lumen
{

class Debug
{
public:
    static void Assert(bool condition, const std::string &message);

    static void Log(const std::string &message);
    static void LogWarning(const std::string &message);
    static void LogError(const std::string &message);
};

} // namespace Lumen