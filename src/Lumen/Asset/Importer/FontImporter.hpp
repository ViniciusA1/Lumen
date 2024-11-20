#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class FontImporter
{
public:
    static Ref<Asset> ImportFont(const AssetMetadata &metadata);
};

} // namespace Lumen