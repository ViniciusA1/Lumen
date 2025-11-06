#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

Scope<ScriptBackend> ScriptEngine::s_Instance;

void ScriptEngine::Init(ScriptBackendType type)
{
    if (s_Instance != nullptr)
        return;

    s_Instance = CreateInstance(type);
}

void ScriptEngine::Shutdown()
{
    s_Instance = nullptr;
}

Scope<ScriptBackend> &ScriptEngine::GetInstance()
{
    return s_Instance;
}

ScriptBackendType ScriptEngine::GetInstanceType()
{
    return s_Instance ? s_Instance->GetType() : ScriptBackendType::None;
}

Scope<ScriptBackend> ScriptEngine::CreateInstance(ScriptBackendType type)
{
    switch (type)
    {
    case ScriptBackendType::None:
        return nullptr;
    case ScriptBackendType::Native:
        return nullptr;
    case ScriptBackendType::Lua:
        return CreateScope<LuaBackend>();
    };

    return nullptr;
}

} // namespace Lumen