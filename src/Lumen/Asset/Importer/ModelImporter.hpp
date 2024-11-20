#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class ModelImporter
{
public:
    static Ref<Asset> ImportModel(const AssetMetadata &metadata);
};

} // namespace Lumen