#pragma once

#include "Lumen/File/Path.hpp"

namespace Lumen
{

struct AssetMetadata
{
    class Path Path;
    std::string Name;

    bool operator==(const AssetMetadata &other) const { return Path == other.Path; }
};

} // namespace Lumen