#pragma once

#include "Lumen/World/Component/UI/DropdownComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const DropdownComponent &dropdown);

template <>
void UpdateUIComponent(TransformComponent &transform, DropdownComponent &dropdown);

} // namespace Lumen