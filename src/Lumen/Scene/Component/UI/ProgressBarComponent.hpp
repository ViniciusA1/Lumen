#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct ProgressBarComponent : public UIComponentBase
{
    float MaxValue = 1.0f;
    float Value = 0.0f;
    Color BackgroundColor = Color::DarkGray;
};

} // namespace Lumen