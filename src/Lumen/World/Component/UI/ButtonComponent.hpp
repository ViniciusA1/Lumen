#pragma once

#include "Lumen/System/Action.hpp"
#include "Lumen/World/Component/UI/LabelComponent.hpp"
#include "Lumen/World/Component/UI/UIComponentBase.hpp"


namespace Lumen
{

struct ButtonComponent : public UIComponentBase
{
    LabelComponent Label;
    AssetHandle Texture;
    Action OnHover;
    Action OnClick;
};

} // namespace Lumen