#include "Lumen/Asset/Importer/MeshImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Mesh Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    return nullptr;
}

template <> bool Export(const Mesh &mesh)
{
    if (!mesh.IsValid())
        return false;

    ::Mesh *rayMesh = mesh;
    ::UnloadMesh(*rayMesh);
    delete rayMesh;
    return true;
}

} // namespace Lumen::AssetImporter