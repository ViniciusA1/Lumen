#pragma once

#include "sol/types.hpp"

namespace Lumen
{

enum class LuaObjectType
{
    None = LUA_TNONE,
    LuaNil = LUA_TNIL,
#if SOL_IS_ON(SOL_NIL)
    Nil = LuaNil,
#endif
    String = LUA_TSTRING,
    Number = LUA_TNUMBER,
    Thread = LUA_TTHREAD,
    Boolean = LUA_TBOOLEAN,
    Function = LUA_TFUNCTION,
    Userdata = LUA_TUSERDATA,
    LightUserdata = LUA_TLIGHTUSERDATA,
    Table = LUA_TTABLE,
    Poly = -0xFFFF
};

} // namespace Lumen