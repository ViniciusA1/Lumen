#include "Lumen/Script/Lua/LuaTable.hpp"

namespace Lumen
{

LuaTable::LuaTable(sol::table table) : m_Table(std::move(table))
{
}

bool LuaTable::IsValid() const
{
    return m_Table.valid() && m_Table != sol::nil;
}

bool LuaTable::Has(const std::string &key) const
{
    sol::object obj = m_Table[key];
    return obj != sol::nil;
}

bool LuaTable::IsEmpty() const
{
    return m_Table.size() == 0;
}

bool LuaTable::IsNil() const
{
    return m_Table == sol::nil;
}

bool LuaTable::IsBoolean() const
{
    return m_Table.is<bool>();
}

bool LuaTable::IsNumber() const
{
    return m_Table.is<double>();
}

bool LuaTable::IsString() const
{
    return m_Table.is<std::string>();
}

bool LuaTable::IsObject() const
{
    return m_Table.is<sol::table>();
}

bool LuaTable::IsFunction() const
{
    return m_Table.is<sol::function>();
}

std::size_t LuaTable::GetSize() const
{
    return m_Table.size();
}

LuaTable LuaTable::GetSubObject(const std::string &key) const
{
    return {m_Table.get<sol::table>(key)};
}

LuaTable LuaTable::CreateSubObject(const std::string &key)
{
    return {m_Table.create(key)};
}

void LuaTable::Clear()
{
    m_Table.clear();
}

void LuaTable::Merge(const LuaTable &other)
{
    other.m_Table.for_each([this](const sol::object &key, const sol::object &value) {
        m_Table.set(key, value);
    });
}

} // namespace Lumen