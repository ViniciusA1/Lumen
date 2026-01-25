#include "Lumen/Asset/Importer/MaterialImporter.hpp"
#include "Lumen/Graphics/Material.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> MaterialImporter::Import(const AssetMetadata &metadata)
{
    int count = 0;
    ::Material *matList = ::LoadMaterials(metadata.Path.String().c_str(), &count);

    Material material = {
        metadata.Handle,
        matList,
    };

    return CreateScope<Material>(material);
}

void MaterialImporter::Export(AssetEntry &entry)
{
    auto *material = entry.GetAsset<Material>();
    if (!material->IsValid())
        return;

    ::Material *rayMaterial = *material;
    ::UnloadMaterial(*rayMaterial);
    delete rayMaterial;
}

} // namespace Lumen