#pragma once

#include "Lumen/Asset/AssetImporter.hpp"

namespace Lumen
{

class SceneImporter : public AssetImporter
{
public:
    Scope<Asset> Import(const AssetMetadata &metadata) override;
    void Export(AssetEntry &entry) override;
};

} // namespace Lumen