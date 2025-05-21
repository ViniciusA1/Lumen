#pragma once

#include "Lumen/Core/Action.hpp"
#include "Lumen/Scene/Component/UI/LabelComponent.hpp"
#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct ButtonComponent : public UIComponentBase
{
    LabelComponent Label;
    AssetHandle Texture;
    Action OnClick;
};

} // namespace Lumen