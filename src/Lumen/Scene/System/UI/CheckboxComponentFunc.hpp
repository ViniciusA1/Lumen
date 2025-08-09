#pragma once

#include "Lumen/Scene/Component/UI/CheckboxComponent.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const CheckboxComponent &checkbox);

template <>
void UpdateUIComponent(TransformComponent &transform, CheckboxComponent &checkbox);

} // namespace Lumen