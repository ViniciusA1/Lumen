#pragma once

#include "Lumen/World/Component/UI/SliderComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const SliderComponent &slider);

template <>
void UpdateUIComponent(TransformComponent &transform, SliderComponent &slider);

} // namespace Lumen