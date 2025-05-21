#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen::AssetImporter
{

template <typename T> T Import(const AssetHandle &uuid, const AssetMetadata &metadata);
template <typename T> bool Export(const T &asset);

} // namespace Lumen::AssetImporter

#include "Lumen/Asset/Importer/AudioImporter.hpp"
#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Asset/Importer/ImageImporter.hpp"
#include "Lumen/Asset/Importer/MeshImporter.hpp"
#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Asset/Importer/TextureImporter.hpp"