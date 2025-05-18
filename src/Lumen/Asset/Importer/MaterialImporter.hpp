#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Material.hpp"

namespace Lumen::AssetImporter
{

template <> Material Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Material &material);

} // namespace Lumen::AssetImporter