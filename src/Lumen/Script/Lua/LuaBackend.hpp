#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Script/Lua/LuaEnum.hpp"
#include "Lumen/Script/Lua/LuaNamespace.hpp"
#include "Lumen/Script/Lua/LuaType.hpp"
#include "Lumen/Script/ScriptBackendType.hpp"
#include "Lumen/Script/ScriptError.hpp"

#include "sol/state.hpp"

namespace Lumen
{

class LuaBackend
{
public:
    LuaBackend();
    ~LuaBackend() = default;

    [[nodiscard]] bool Has(const std::string &name) const;

    template <typename T> T Get(const std::string &name);

    [[nodiscard]] ScriptBackendType GetType() const;

    template <typename T> void Set(const std::string &name, const T &value);

    ScriptError ExecuteFile(const Path &path);
    ScriptError ExecuteString(const std::string &code);
    ScriptError LoadFile(const Path &path);
    ScriptError LoadString(const std::string &code);

    template <typename Ret, typename... Args>
    Ret Call(const std::string &funcName, Args &&...args);
    template <typename... Args> void Call(const std::string &funcName, Args &&...args);

    template <typename T> LuaEnum<T> RegisterEnum(const std::string &name);
    inline LuaNamespace RegisterNamespace(const std::string &name);
    template <typename T> LuaType<T> RegisterType(const std::string &name);

private:
    sol::state m_Lua;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaBackend.inl"