#include "Lumen/Scene/System/UI/CheckboxComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const CheckboxComponent &checkbox)
{
}

template <>
void UpdateUIComponent(TransformComponent &transform, CheckboxComponent &checkbox)
{
}

} // namespace Lumen