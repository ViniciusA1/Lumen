#pragma once

#include "Lumen/Script/Lua/LuaEnum.hpp"

namespace Lumen
{

template <typename T>
LuaEnum<T>::LuaEnum(sol::state_view enumTable) : m_EnumTable(std::move(enumTable))
{
}

template <typename T> LuaEnum<T> &LuaEnum<T>::Value(const std::string &name, T value)
{
    m_EnumTable[name] = value;
    return *this;
}

template <typename T>
LuaEnum<T> &LuaEnum<T>::Values(std::initializer_list<std::pair<std::string, T>> list)
{
    for (auto &pair : list)
        m_EnumTable[pair.first] = pair.second;

    return *this;
}

} // namespace Lumen