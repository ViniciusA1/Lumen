#pragma once

#include "Lumen/World/Component/UI/LabelComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const LabelComponent &label);

template <> void UpdateUIComponent(TransformComponent &transform, LabelComponent &label);

} // namespace Lumen