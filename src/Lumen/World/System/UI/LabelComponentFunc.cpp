#include "Lumen/World/System/UI/LabelComponentFunc.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Graphics/Renderer.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const LabelComponent &label)
{
    Renderer::DrawText(transform, label.Text, label.FontSize,
                       label.Colors[static_cast<int>(label.State)],
                       AssetManager::Get<Font>(label.Font));
}

template <> void UpdateUIComponent(TransformComponent &transform, LabelComponent &label)
{
}

} // namespace Lumen