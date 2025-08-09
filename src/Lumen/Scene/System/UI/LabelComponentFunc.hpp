#pragma once

#include "Lumen/Scene/Component/UI/LabelComponent.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const LabelComponent &label);

template <> void UpdateUIComponent(TransformComponent &transform, LabelComponent &label);

} // namespace Lumen