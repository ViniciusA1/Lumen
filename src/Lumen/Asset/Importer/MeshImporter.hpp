#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class MeshImporter
{
public:
    static Ref<Asset> ImportMesh(const AssetMetadata &metadata);
};

} // namespace Lumen