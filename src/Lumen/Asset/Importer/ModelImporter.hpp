#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Model.hpp"

namespace Lumen::AssetImporter
{

template <> Model Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Model &model);

} // namespace Lumen::AssetImporter