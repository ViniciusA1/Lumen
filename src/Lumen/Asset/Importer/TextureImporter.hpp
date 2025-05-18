#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Texture.hpp"

namespace Lumen::AssetImporter
{

template <> Texture2D Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Texture2D &texture);

Texture2D LoadTextureFromImage(const Image &image);

} // namespace Lumen::AssetImporter