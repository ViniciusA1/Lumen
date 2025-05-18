#include "Lumen/Asset/Importer/MaterialImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Material Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    int materialCount = 0;
    ::Material *materialList =
        ::LoadMaterials(metadata.Path.String().c_str(), &materialCount);

    if (materialCount == 0)
        return nullptr;

    return {materialList};
}

template <> bool Export(const Material &material)
{
    if (!material.IsValid())
        return false;

    ::Material *rayMaterial = material;
    ::UnloadMaterial(*rayMaterial);
    delete rayMaterial;
    return true;
}

} // namespace Lumen::AssetImporter