#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetEntry.hpp"
#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen
{

class AssetImporter
{
public:
    virtual Scope<Asset> Import(const AssetMetadata &metadata) = 0;
    virtual void Export(AssetEntry &entry) = 0;
};

class DefaultAssetImporter
{
public:
    virtual Scope<Asset> Import() = 0;
};

} // namespace Lumen