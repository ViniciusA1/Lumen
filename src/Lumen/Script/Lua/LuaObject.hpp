#pragma once

#include "Lumen/Script/Lua/LuaObjectType.hpp"
#include "Lumen/Script/Lua/LuaTable.hpp"

#include "sol/object.hpp"
#include "sol/userdata.hpp"

namespace Lumen
{

class LuaObject
{
public:
    LuaObject() = default;
    LuaObject(sol::object object);

    [[nodiscard]] bool IsBool() const;
    [[nodiscard]] bool IsFunction() const;
    [[nodiscard]] bool IsLightUserdata() const;
    [[nodiscard]] bool IsNil() const;
    [[nodiscard]] bool IsNumber() const;
    [[nodiscard]] bool IsString() const;
    [[nodiscard]] bool IsTable() const;
    [[nodiscard]] bool IsUserdata() const;
    [[nodiscard]] bool IsValid() const;

    template <typename T> [[nodiscard]] bool Is() const;

    template <typename T> T As() const;
    template <typename T> std::optional<T> TryAs() const;

    [[nodiscard]] LuaTable AsTable() const;
    [[nodiscard]] sol::userdata AsUserdata() const;

    [[nodiscard]] LuaObjectType GetType() const;

    template <typename Key, typename T> T Get(const Key &key) const;
    template <typename Key, typename T> std::optional<T> TryGet(const Key &key) const;

    template <typename Key, typename T> void Set(const Key &key, const T &val);

private:
    sol::object m_Object;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaObject.inl"