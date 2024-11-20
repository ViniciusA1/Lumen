#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

namespace Lumen
{

class ShaderImporter
{
public:
    static Ref<Asset> ImportShader(const AssetMetadata &metadata);
};

} // namespace Lumen