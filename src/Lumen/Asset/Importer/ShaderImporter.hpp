#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Shader.hpp"

namespace Lumen::AssetImporter
{

template <> Shader Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Shader &shader);

} // namespace Lumen::AssetImporter