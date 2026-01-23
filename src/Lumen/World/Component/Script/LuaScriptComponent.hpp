#pragma once

#include "Lumen/Script/Lua/LuaTable.hpp"
#include <string>
#include <unordered_map>

namespace Lumen
{

struct LuaScriptComponent
{
    struct Info
    {
        LuaTable Data;
    };

    std::unordered_map<std::string, Info> Components;
};

} // namespace Lumen