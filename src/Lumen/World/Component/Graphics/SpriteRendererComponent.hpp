#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Graphics/Color.hpp"

namespace Lumen
{

struct SpriteRendererComponent
{
    class Color Color = Color::White;
    AssetHandle Texture;
};

} // namespace Lumen