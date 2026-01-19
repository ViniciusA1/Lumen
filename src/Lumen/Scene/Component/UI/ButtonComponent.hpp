#pragma once

#include "Lumen/Scene/Component/UI/LabelComponent.hpp"
#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"
#include "Lumen/System/Action.hpp"

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