#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class ImageImporter
{
public:
    static Ref<Asset> ImportImage(const AssetMetadata &metadata);
};

} // namespace Lumen