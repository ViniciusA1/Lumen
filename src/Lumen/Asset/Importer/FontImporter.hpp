#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Font.hpp"

namespace Lumen::AssetImporter
{

template <> Font Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Font &font);

} // namespace Lumen::AssetImporter