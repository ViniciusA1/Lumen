#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Graphics/Color.hpp"

namespace Lumen
{

struct SpriteRendererComponent
{
    Color Color = Color::White;
    UUID Texture = 0;
};

} // namespace Lumen