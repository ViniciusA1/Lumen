#include "Lumen/Script/ScriptError.hpp"

namespace Lumen
{

ScriptError::ScriptError(ScriptErrorType type, std::string message,
                         std::string scriptName, int line)
    : m_Type(type), m_Message(std::move(message)), m_ScriptName(std::move(scriptName)),
      m_Line(line)
{
}

int ScriptError::GetLine() const
{
    return m_Line;
}

const std::string &ScriptError::GetMessage() const
{
    return m_Message;
}

const std::string &ScriptError::GetScriptName() const
{
    return m_ScriptName;
}

ScriptErrorType ScriptError::GetType() const
{
    return m_Type;
}

} // namespace Lumen