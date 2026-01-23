#include "Lumen/World/System/UI/SliderComponentFunc.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const SliderComponent &slider)
{
}

template <> void UpdateUIComponent(TransformComponent &transform, SliderComponent &slider)
{
}

} // namespace Lumen