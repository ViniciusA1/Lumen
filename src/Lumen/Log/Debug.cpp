#include "Lumen/Log/Debug.hpp"
#include "Lumen/Log/Log.hpp"

namespace Lumen
{

void Debug::Assert(bool condition, const std::string &message)
{
    if (!condition)
    {
        LM_CRITICAL("Assertion Failed: {}", message);
        throw std::runtime_error("Assertion Failed: " + message);
    }
}

void Debug::LogTrace(const std::string &message)
{
    LM_TRACE(message);
}

void Debug::LogInfo(const std::string &message)
{
    LM_INFO(message);
}

void Debug::LogWarning(const std::string &message)
{
    LM_WARN(message);
}

void Debug::LogError(const std::string &message)
{
    LM_ERROR(message);
}

void Debug::LogCritical(const std::string &message)
{
    LM_CRITICAL(message);
}

} // namespace Lumen