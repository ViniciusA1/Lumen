#pragma once

#include "Lumen/World/Component/UI/ButtonComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const ButtonComponent &button);

template <>
void UpdateUIComponent(TransformComponent &transform, ButtonComponent &button);

} // namespace Lumen