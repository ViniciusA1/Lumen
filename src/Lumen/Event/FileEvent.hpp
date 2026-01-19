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
    class Path Path;
    FileEventType Type;
};

} // namespace Lumen