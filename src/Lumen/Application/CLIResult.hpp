#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"

namespace Lumen
{

struct CLIResult
{
    bool ShouldRun = false;
    ApplicationArgs Args;
};

} // namespace Lumen