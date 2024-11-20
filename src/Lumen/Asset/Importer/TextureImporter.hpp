#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class TextureImporter
{
public:
    static Ref<Asset> ImportTexture(const AssetMetadata &metadata);
};

} // namespace Lumen