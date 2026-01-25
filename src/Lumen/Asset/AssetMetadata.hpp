#pragma once

#include "AssetStatus.hpp"
#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Asset/AssetType.hpp"
#include "Lumen/File/Path.hpp"

namespace Lumen
{

struct AssetMetadata
{
    AssetHandle Handle;
    Lumen::Path Path = "";
    AssetType Type = AssetType::None;
    AssetStatus Status = AssetStatus::NotImported;

    bool operator==(const AssetMetadata &other) const;
    bool operator!=(const AssetMetadata &other) const;
};

} // namespace Lumen