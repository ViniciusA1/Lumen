#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Audio/Audio.hpp"

namespace Lumen::AssetImporter
{

template <> Audio Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Audio &audio);

} // namespace Lumen::AssetImporter