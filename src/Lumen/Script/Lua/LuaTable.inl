#pragma once

#include "Lumen/Script/Lua/LuaTable.hpp"

namespace Lumen
{

template <typename T> bool LuaTable::Is() const
{
    return m_Table.is<T>();
}

template <typename T> T LuaTable::As() const
{
    return m_Table.as<T>();
}

template <typename T> T LuaTable::Get(const std::string &key) const
{
    return m_Table.get<T>(key);
}

template <typename T> T LuaTable::Get(const std::string &key, T &&defaultValue) const
{
    return m_Table.get_or<T>(key, std::forward<T>(defaultValue));
}

template <typename T> T LuaTable::GetAt(std::size_t index) const
{
    return m_Table.get<T>(index);
}

template <typename T> void LuaTable::Set(const std::string &key, T &&value)
{
    m_Table.set(key, std::forward<T>(value));
}

template <typename T> void LuaTable::SetAt(std::size_t index, T &&value)
{
    m_Table.set(index, std::forward<T>(value));
}

template <typename T> void LuaTable::PushBack(T &&value)
{
    m_Table.add(std::forward<T>(value));
}

template <typename... Args>
void LuaTable::Call(const std::string &functionName, Args &&...args)
{
    sol::function func = m_Table[functionName];
    if (func.valid())
        func(std::forward<Args>(args)...);
}

template <typename Function> void LuaTable::ForEach(Function &&func) const
{
    m_Table.for_each(std::forward<Function>(func));
}

} // namespace Lumen