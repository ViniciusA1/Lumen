#pragma once

#include "Lumen/World/Component/UI/ProgressBarComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const ProgressBarComponent &progressBar);

template <>
void UpdateUIComponent(TransformComponent &transform, ProgressBarComponent &progressBar);

} // namespace Lumen