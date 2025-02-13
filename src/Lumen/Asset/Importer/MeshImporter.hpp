#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Mesh.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Mesh> Import(UUID uuid, const AssetMetadata &metadata);
template <> bool Export(const Ref<Mesh> &mesh);

} // namespace Lumen::AssetImporter