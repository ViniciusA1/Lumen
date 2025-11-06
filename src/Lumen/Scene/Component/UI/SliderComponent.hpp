#pragma once

#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct SliderComponent : public UIComponentBase
{
    float MinValue = 0.0f;
    float MaxValue = 1.0f;
    float Value = 0.0f;
};

} // namespace Lumen