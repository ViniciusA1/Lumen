#include "Lumen/Scene/System/UI/InputFieldComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const InputFieldComponent &inputField)
{
}

template <>
void UpdateUIComponent(TransformComponent &transform, InputFieldComponent &inputField)
{
}

} // namespace Lumen