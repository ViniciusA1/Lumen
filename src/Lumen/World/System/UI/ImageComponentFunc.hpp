#pragma once

#include "Lumen/World/Component/UI/ImageComponent.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const ImageComponent &image);

template <> void UpdateUIComponent(TransformComponent &transform, ImageComponent &image);

} // namespace Lumen