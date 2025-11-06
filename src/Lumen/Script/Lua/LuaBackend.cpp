#include "Lumen/Script/Lua/LuaBackend.hpp"

namespace Lumen
{

LuaBackend::LuaBackend() : m_Lua(sol::state())
{
    m_Lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::table);
}

bool LuaBackend::Has(const std::string &name) const
{
    return m_Lua[name].valid();
}

ScriptBackendType LuaBackend::GetType() const
{
    return ScriptBackendType::Lua;
}

ScriptError LuaBackend::ExecuteFile(const Path &path)
{
    sol::function_result result = m_Lua.script_file(path.String());

    return {ScriptErrorType::None, ""};
}

ScriptError LuaBackend::ExecuteString(const std::string &code)
{
    sol::protected_function_result result =
        m_Lua.safe_script(code, &sol::script_pass_on_error);

    return {ScriptErrorType::None, ""};
}

ScriptError LuaBackend::LoadFile(const Path &path)
{
    sol::load_result result = m_Lua.load_file(path.String());
    if (result.valid())
    {
        result();
        return {ScriptErrorType::None, ""};
    }

    sol::error err = result;
    return {ScriptErrorType::Syntax, err.what(), path.String()};
}

ScriptError LuaBackend::LoadString(const std::string &code)
{
    sol::load_result result = m_Lua.load(code);
    if (result.valid())
        return {ScriptErrorType::None, ""};

    sol::error err = result;
    return {ScriptErrorType::Syntax, err.what()};
}

} // namespace Lumen