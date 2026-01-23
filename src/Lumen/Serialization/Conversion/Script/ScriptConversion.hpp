#pragma once

#include "Lumen/Serialization/Json.hpp"

#include "Lumen/Script/Lua/LuaObject.hpp"
#include "Lumen/Script/Lua/LuaTable.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LuaTable &rootTable);
template <> void Deserialize(const Json &json, LuaTable &rootTable);

template <> Json Serialize(const LuaObject &object);
template <> void Deserialize(const Json &json, LuaObject &object);

} // namespace Lumen::JsonSerializer