#pragma once

#include "sol/state_view.hpp"

namespace Lumen
{

template <typename T> class LuaEnum
{
public:
    LuaEnum(sol::state_view enumTable);

    LuaEnum &Value(const std::string &name, T value);
    LuaEnum &Values(std::initializer_list<std::pair<std::string, T>> list);

private:
    sol::state_view m_EnumTable;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaEnum.inl"