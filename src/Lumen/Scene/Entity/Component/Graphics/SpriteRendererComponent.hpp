#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct SpriteRendererComponent : public ComponentBase
{
    Color Color = Color::White;
    Ref<Texture2D> Texture;

    SpriteRendererComponent() = default;
    SpriteRendererComponent(const Ref<Texture2D> &texture,
                            const class Color &color = Color::White)
        : Texture(texture), Color(color)
    {
    }
};

} // namespace Lumen