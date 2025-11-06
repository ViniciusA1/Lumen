#pragma once

#include "Lumen/Scene/Component/UI/InputFieldComponent.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const InputFieldComponent &inputField);

template <>
void UpdateUIComponent(TransformComponent &transform, InputFieldComponent &inputField);

} // namespace Lumen