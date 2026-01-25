#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetMetadata.hpp"
#include "Lumen/Memory/Memory.hpp"

namespace Lumen
{

struct AssetEntry
{
    AssetMetadata Metadata;
    Scope<Asset> Asset;

    template <typename T> T *GetAsset() { return static_cast<T *>(Asset.get()); }
};

} // namespace Lumen