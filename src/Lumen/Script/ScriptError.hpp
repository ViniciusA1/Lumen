#pragma once

#include "Lumen/Script/ScriptErrorType.hpp"

#include <string>

namespace Lumen
{

class ScriptError
{
public:
    ScriptError(ScriptErrorType type, std::string message, std::string scriptName = "",
                int line = -1);

    [[nodiscard]] int GetLine() const;
    [[nodiscard]] const std::string &GetMessage() const;
    [[nodiscard]] const std::string &GetScriptName() const;
    [[nodiscard]] ScriptErrorType GetType() const;

private:
    ScriptErrorType m_Type = ScriptErrorType::None;
    std::string m_Message;
    std::string m_ScriptName;
    int m_Line = -1;
};

} // namespace Lumen