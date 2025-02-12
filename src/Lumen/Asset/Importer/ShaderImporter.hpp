#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Shader.hpp"

namespace Lumen::AssetImporter
{

template <> Ref<Shader> Import(const AssetMetadata &metadata);
template <> bool Export(const Ref<Shader> &shader);

} // namespace Lumen::AssetImporter