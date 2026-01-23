#pragma once

#include "Lumen/Script/Lua/LuaObject.hpp"

namespace Lumen
{

template <typename T> bool LuaObject::Is() const
{
    return m_Object.is<T>();
}

template <typename T> T LuaObject::As() const
{
    return m_Object.as<T>();
}

template <typename T> std::optional<T> LuaObject::TryAs() const
{
    if (m_Object.is<T>())
        return m_Object.as<T>();
    return std::nullopt;
}

template <typename Key, typename T> T LuaObject::Get(const Key &key) const
{
    return m_Object.as<sol::table>()[key].template as<T>();
}

template <typename Key, typename T>
std::optional<T> LuaObject::TryGet(const Key &key) const
{
    auto tbl = m_Object.as<sol::table>();
    sol::object value = tbl.get<sol::object>(key);
    if (value.is<T>())
        return value.as<T>();
    return std::nullopt;
}

template <typename Key, typename T> void LuaObject::Set(const Key &key, const T &val)
{
    auto tbl = m_Object.as<sol::table>();
    tbl[key] = val;
}

} // namespace Lumen