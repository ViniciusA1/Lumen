#pragma once

#include "Lumen/Scene/Component/UI/ButtonComponent.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const ButtonComponent &button);

template <>
void UpdateUIComponent(TransformComponent &transform, ButtonComponent &button);

} // namespace Lumen