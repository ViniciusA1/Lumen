#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/File/Path.hpp"

namespace Lumen
{

class AssetMetadata
{
public:
    Path Path;

    UUID ID;
    std::string Name;

public:
    AssetMetadata() = default;
    AssetMetadata(UUID uuid, std::string name, class Path path);
    AssetMetadata(std::string name, class Path path);
};

} // namespace Lumen