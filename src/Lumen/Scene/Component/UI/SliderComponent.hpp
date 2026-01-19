#pragma once

#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct SliderComponent : public UIComponentBase
{
    float Min = 0.0f;
    float Max = 1.0f;
    float Value = 0.0f;
};

} // namespace Lumen