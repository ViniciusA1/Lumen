#pragma once

#include "Lumen/File/Path.hpp"

namespace Lumen
{

class AssetMetadata
{
public:
    Path Path;
    std::string Name;

public:
    AssetMetadata() = default;
    AssetMetadata(class Path path, std::string name);
};

} // namespace Lumen