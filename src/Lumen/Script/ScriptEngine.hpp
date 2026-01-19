#pragma once

#include "Lumen/Memory/Memory.hpp"
#include "Lumen/Script/ScriptBackend.hpp"
#include "Lumen/Script/ScriptBackendType.hpp"

namespace Lumen
{

class LuaInstance;

class ScriptEngine
{
public:
    ScriptEngine() = delete;

public:
    static void Init(ScriptBackendType type);
    static void Shutdown();

    static Scope<ScriptBackend> &GetInstance();
    static ScriptBackendType GetInstanceType();

private:
    static Scope<ScriptBackend> CreateInstance(ScriptBackendType type);

private:
    static Scope<ScriptBackend> s_Instance;
};

} // namespace Lumen