#include "Lumen/Asset/Importer/MeshImporter.hpp"
#include "Lumen/Graphics/Mesh.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> MeshImporter::Import(const AssetMetadata &metadata)
{
    return nullptr;
}

void MeshImporter::Export(AssetEntry &entry)
{
    auto *mesh = entry.GetAsset<Mesh>();
    if (!mesh->IsValid())
        return;

    ::Mesh *rayMesh = *mesh;
    ::UnloadMesh(*rayMesh);
    delete rayMesh;
}

} // namespace Lumen