#pragma once

#include "Lumen/Scene/Component/UI/SliderComponent.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const SliderComponent &slider);

template <>
void UpdateUIComponent(TransformComponent &transform, SliderComponent &slider);

} // namespace Lumen