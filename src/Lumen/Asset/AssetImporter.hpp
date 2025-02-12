#pragma once

#include "Lumen/Asset/AssetMetadata.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen::AssetImporter
{

template <typename T> Ref<T> Import(const AssetMetadata &metadata);
template <typename T> bool Export(const Ref<T> &asset);

} // namespace Lumen::AssetImporter

#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Asset/Importer/ImageImporter.hpp"
#include "Lumen/Asset/Importer/MeshImporter.hpp"
#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Asset/Importer/TextureImporter.hpp"