#pragma once

#include "sol/table.hpp"
#include <string>

namespace Lumen
{

class LuaTable
{
public:
    LuaTable() = default;
    LuaTable(sol::table table);

    [[nodiscard]] bool IsValid() const;

    template <typename T> [[nodiscard]] bool Is() const;

    [[nodiscard]] bool Has(const std::string &key) const;

    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] bool IsNil() const;
    [[nodiscard]] bool IsBoolean() const;
    [[nodiscard]] bool IsNumber() const;
    [[nodiscard]] bool IsString() const;
    [[nodiscard]] bool IsObject() const;
    [[nodiscard]] bool IsFunction() const;

    [[nodiscard]] std::size_t GetSize() const;
    [[nodiscard]] LuaTable GetSubObject(const std::string &key) const;

    template <typename T> T As() const;

    template <typename T> T Get(const std::string &key) const;
    template <typename T> T Get(const std::string &key, T &&defaultValue) const;
    template <typename T> T GetAt(std::size_t index) const;

    LuaTable CreateSubObject(const std::string &key);

    template <typename T> void Set(const std::string &key, T &&value);
    template <typename T> void SetAt(std::size_t index, T &&value);

    template <typename T> void PushBack(T &&value);

    template <typename... Args>
    void Call(const std::string &functionName, Args &&...args);

    template <typename Function> void ForEach(Function &&func) const;

    void Clear();
    void Merge(const LuaTable &other);

private:
    sol::table m_Table;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaTable.inl"