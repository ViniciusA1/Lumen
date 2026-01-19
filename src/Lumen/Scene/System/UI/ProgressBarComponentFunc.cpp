#include "Lumen/Scene/System/UI/ProgressBarComponentFunc.hpp"
#include "Lumen/Graphics/Renderer.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const ProgressBarComponent &progressBar)
{
    Renderer::DrawQuad(transform, progressBar.BackgroundColor);

    float progress = Math::Clamp(progressBar.Value / progressBar.MaxValue, 0.0f, 1.0f);
    TransformComponent fillTransform = {
        transform.Position,
        {},
        {transform.Scale.x * progress, transform.Scale.y},
    };

    Renderer::DrawQuad(fillTransform,
                       progressBar.Colors[static_cast<int>(progressBar.State)]);
}

template <>
void UpdateUIComponent(TransformComponent &transform, ProgressBarComponent &progressBar)
{
}

} // namespace Lumen