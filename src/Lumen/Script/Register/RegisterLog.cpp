#include "Lumen/Log/Debug.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterDebug();

void RegisterLogAPI()
{
    RegisterDebug();
}

static void RegisterDebug()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Debug>("Debug")
        .StaticMethod("assert", &Debug::Assert)
        .StaticMethod("log_trace", &Debug::LogTrace)
        .StaticMethod("log_info", &Debug::LogInfo)
        .StaticMethod("log_warning", &Debug::LogWarning)
        .StaticMethod("log_error", &Debug::LogError)
        .StaticMethod("log_critical", &Debug::LogCritical);
}

} // namespace Lumen