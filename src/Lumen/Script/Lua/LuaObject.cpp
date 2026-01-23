#include "Lumen/Script/Lua/LuaObject.hpp"

namespace Lumen
{

LuaObject::LuaObject(sol::object object) : m_Object(std::move(object))
{
}

bool LuaObject::IsBool() const
{
    return m_Object.is<bool>();
}

bool LuaObject::IsFunction() const
{
    return m_Object.get_type() == sol::type::function;
}

bool LuaObject::IsLightUserdata() const
{
    return m_Object.get_type() == sol::type::lightuserdata;
}

bool LuaObject::IsNil() const
{
    return m_Object.is<sol::nil_t>();
}

bool LuaObject::IsNumber() const
{
    return m_Object.is<double>() || m_Object.is<int>();
}

bool LuaObject::IsString() const
{
    return m_Object.is<std::string>();
}

bool LuaObject::IsTable() const
{
    return m_Object.get_type() == sol::type::table;
}

bool LuaObject::IsUserdata() const
{
    return m_Object.get_type() == sol::type::userdata;
}

bool LuaObject::IsValid() const
{
    return m_Object.valid();
}

LuaTable LuaObject::AsTable() const
{
    return m_Object.as<sol::table>();
}

sol::userdata LuaObject::AsUserdata() const
{
    return m_Object.as<sol::userdata>();
}

LuaObjectType LuaObject::GetType() const
{
    return static_cast<LuaObjectType>(m_Object.get_type());
}

} // namespace Lumen