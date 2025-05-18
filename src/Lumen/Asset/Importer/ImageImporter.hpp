#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Texture.hpp"

namespace Lumen::AssetImporter
{

template <> Image Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Image &image);

Image LoadImageFromTexture(const Texture2D &texture);

} // namespace Lumen::AssetImporter