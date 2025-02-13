#include "Lumen/Asset/Importer/MeshImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Mesh> Import(UUID uuid, const AssetMetadata &metadata)
{
    return nullptr;
}

template <> bool Export(const Ref<Mesh> &mesh)
{
    if (!mesh->IsValid())
    {
        return false;
    }

    ::UnloadMesh(*mesh);
    return true;
}

} // namespace Lumen::AssetImporter