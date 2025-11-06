#pragma once

#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Audio/Music.hpp"
#include "Lumen/Audio/Sound.hpp"
#include "Lumen/Audio/Wave.hpp"

namespace Lumen::AssetImporter
{

template <> Music Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Music &music);

template <> Sound Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Sound &sound);

template <> Wave Import(const AssetHandle &handle, const AssetMetadata &metadata);
template <> bool Export(const Wave &wave);

} // namespace Lumen::AssetImporter