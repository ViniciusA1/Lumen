#pragma once

#include "Lumen/File/Path.hpp"
namespace Lumen
{

enum class FileEventType
{
    Modified,
    Created,
    Deleted
};

struct FileEvent
{
    FileEventType Type;
    Lumen::Path Path;
};

} // namespace Lumen