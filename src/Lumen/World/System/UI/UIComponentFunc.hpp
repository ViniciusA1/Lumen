#pragma once

#include "Lumen/World/Component/Core/TransformComponent.hpp"

namespace Lumen
{

template <typename T>
void DrawUIComponent(const TransformComponent &transform, const T &component)
{
}

template <typename T> void UpdateUIComponent(TransformComponent &transform, T &component)
{
}

} // namespace Lumen

#include "Lumen/World/System/UI/ButtonComponentFunc.hpp"
#include "Lumen/World/System/UI/LabelComponentFunc.hpp"