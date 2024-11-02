#include "Lumen/Core/Debug.hpp"
#include "raylib.h"

namespace Lumen
{

void Debug::Assert(bool condition, const std::string &message)
{
    if (condition)
    {
        TraceLog(LOG_FATAL, message.c_str());
    }
}

void Debug::Log(const std::string &message)
{
    TraceLog(LOG_INFO, message.c_str());
}

void Debug::LogWarning(const std::string &message)
{
    TraceLog(LOG_WARNING, message.c_str());
}

void Debug::LogError(const std::string &message)
{
    TraceLog(LOG_ERROR, message.c_str());
}

} // namespace Lumen