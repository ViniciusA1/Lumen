#pragma once

#include "Lumen/Graphics/Font.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Material.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Graphics/Texture.hpp"

namespace Lumen::DefaultAssetImporter
{

template <typename T> T Import()
{
    return {};
}

template <> Font Import();
template <> Image Import();
template <> Material Import();
template <> Mesh Import();
template <> Shader Import();
template <> Texture2D Import();

} // namespace Lumen::DefaultAssetImporter