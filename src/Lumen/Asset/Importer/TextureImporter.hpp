#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Texture.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Texture2D> Import(const AssetMetadata &metadata);
template <> bool Export(const Ref<Texture2D> &texture);

} // namespace Lumen::AssetImporter