#pragma once

#include "Lumen/Script/Lua/LuaBackend.hpp"

namespace Lumen
{

template <typename T> T LuaBackend::Get(const std::string &name)
{
    return m_Lua[name].get<T>();
}

template <typename T> void LuaBackend::Set(const std::string &name, const T &value)
{
    m_Lua[name] = value;
}

template <typename Ret, typename... Args>
Ret LuaBackend::Call(const std::string &funcName, Args &&...args)
{
    sol::function func = m_Lua[funcName];
    if (!func.valid())
        return Ret();

    sol::protected_function_result result = func(std::forward<Args>(args)...);
    if (!result.valid())
        return Ret();

    return result.get<Ret>();
}

template <typename... Args>
void LuaBackend::Call(const std::string &funcName, Args &&...args)
{
    sol::function func = m_Lua[funcName];
    if (!func.valid())
        return;

    sol::protected_function_result result = func(std::forward<Args>(args)...);
}

template <typename T> LuaEnum<T> LuaBackend::RegisterEnum(const std::string &name)
{
    return m_Lua.new_enum(name);
}

LuaNamespace LuaBackend::RegisterNamespace(const std::string &name)
{
    return m_Lua.create_named_table(name);
}

template <typename T> LuaType<T> LuaBackend::RegisterType(const std::string &name)
{
    return m_Lua.new_usertype<T>(name);
}

} // namespace Lumen