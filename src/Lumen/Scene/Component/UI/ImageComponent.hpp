#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct ImageComponent : public UIComponentBase
{
    AssetHandle Texture;
};

} // namespace Lumen