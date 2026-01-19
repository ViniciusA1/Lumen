#pragma once

#include "Lumen/Script/Lua/LuaNamespace.hpp"

namespace Lumen
{

inline LuaNamespace::LuaNamespace(sol::table table) : m_Table(std::move(table))
{
}

template <typename Value>
inline LuaNamespace &LuaNamespace::StaticProperty(const std::string &name, Value &&value)
{
    m_Table.set(name, std::forward<Value>(value));
    return *this;
}

template <typename Func, typename... Funcs>
inline LuaNamespace &LuaNamespace::Function(const std::string &name, Func function,
                                            Funcs &&...functions)
{
    m_Table.set(name, sol::overload(function, std::forward<Funcs>(functions)...));
    return *this;
}

} // namespace Lumen