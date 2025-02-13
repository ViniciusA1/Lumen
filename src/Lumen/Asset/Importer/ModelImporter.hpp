#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Model.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Model> Import(UUID uuid, const AssetMetadata &metadata);
template <> bool Export(const Ref<Model> &model);

} // namespace Lumen::AssetImporter