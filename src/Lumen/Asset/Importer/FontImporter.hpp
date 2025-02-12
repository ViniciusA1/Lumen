#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Font.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Font> Import(const AssetMetadata &metadata);
template <> bool Export(const Ref<Font> &font);

} // namespace Lumen::AssetImporter