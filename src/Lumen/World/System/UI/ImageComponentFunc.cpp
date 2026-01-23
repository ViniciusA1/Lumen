#include "Lumen/World/System/UI/ImageComponentFunc.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Graphics/Renderer.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const ImageComponent &image)
{
    Renderer::DrawQuad(transform, AssetManager::Get<Texture2D>(image.Texture), image.UV,
                       image.Colors[static_cast<int>(image.State)]);
}

template <> void UpdateUIComponent(TransformComponent &transform, ImageComponent &image)
{
}

} // namespace Lumen