#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Mesh.hpp"

namespace Lumen::AssetImporter
{

template <> Mesh Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Mesh &mesh);

} // namespace Lumen::AssetImporter