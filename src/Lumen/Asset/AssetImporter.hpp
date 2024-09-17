#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"
#include <typeindex>

namespace Lumen
{

class AssetImporter
{
public:
    static Ref<Asset> ImportAsset(std::type_index type, const AssetMetadata &metadata);
};

} // namespace Lumen