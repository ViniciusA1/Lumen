#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Image.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Image> Import(UUID uuid, const AssetMetadata &metadata);
template <> bool Export(const Ref<Image> &image);

} // namespace Lumen::AssetImporter