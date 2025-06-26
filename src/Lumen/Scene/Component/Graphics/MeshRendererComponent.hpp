#pragma once

#include "Lumen/Asset/AssetHandle.hpp"

namespace Lumen
{

struct MeshRendererComponent
{
    AssetHandle Mesh;
    AssetHandle Material;
};

} // namespace Lumen