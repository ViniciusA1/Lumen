#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Serialization/SerializationStatus.hpp"

#include <string>

namespace Lumen
{

struct SerializationMessage
{
    SerializationStatus Status;
    std::string Message;
    Lumen::Path Path;
};

} // namespace Lumen