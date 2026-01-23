#pragma once

#include "Lumen/World/Component/UI/InputFieldComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const InputFieldComponent &inputField);

template <>
void UpdateUIComponent(TransformComponent &transform, InputFieldComponent &inputField);

} // namespace Lumen