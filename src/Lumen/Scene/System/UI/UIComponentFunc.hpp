#pragma once

#include "Lumen/Scene/Component/Core/TransformComponent.hpp"

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

#include "Lumen/Scene/System/UI/ButtonComponentFunc.hpp"
#include "Lumen/Scene/System/UI/LabelComponentFunc.hpp"