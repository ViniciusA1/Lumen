#pragma once

namespace Lumen
{

enum class ScriptErrorType
{
    None = 0,
    Syntax,
    Runtime,
    Type,
    Memory,
    Internal,
    Unknown
};

} // namespace Lumen