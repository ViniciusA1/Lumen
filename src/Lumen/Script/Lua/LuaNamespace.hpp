#pragma once

#include "sol/table.hpp"

namespace Lumen
{

class LuaNamespace
{
public:
    inline LuaNamespace(sol::table table);

    template <typename Value>
    inline LuaNamespace &StaticProperty(const std::string &name, Value &&value);

    template <typename Func, typename... Funcs>
    inline LuaNamespace &Function(const std::string &name, Func function,
                                  Funcs &&...functions);

private:
    sol::table m_Table;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaNamespace.inl"