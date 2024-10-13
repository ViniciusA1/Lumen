#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"

namespace Lumen
{

struct SpriteRendererComponent
{
    Color Color = Color::White;
    Ref<Texture2D> Texture;

    SpriteRendererComponent() = default;
    SpriteRendererComponent(const class Color &color) : Color(color) {}
};

} // namespace Lumen