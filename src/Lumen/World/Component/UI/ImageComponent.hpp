#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/World/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct ImageComponent : public UIComponentBase
{
    AssetHandle Texture;
    Vector4 UV = {0, 0, 1, 1};
};

} // namespace Lumen