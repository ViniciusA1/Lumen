#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"

namespace Lumen
{

class ApplicationArgsSerializer
{
public:
    ApplicationArgsSerializer() = default;

    bool Deserialize(ApplicationArgs &args, const Path &path);
    bool Serialize(const ApplicationArgs &args, const Path &path);
};

} // namespace Lumen