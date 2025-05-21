#include "Lumen/Asset/Importer/DefaultImporter.hpp"

#include "raylib.h"

namespace Lumen::DefaultAssetImporter
{

template <> Audio Import()
{
    return {};
}

template <> Font Import()
{
    return ::GetFontDefault();
}

template <> Image Import()
{
    constexpr int width = 64;
    constexpr int height = 64;
    return ::GenImageColor(width, height, WHITE);
}

template <> Material Import()
{
    return LoadMaterialDefault();
}

template <> Mesh Import()
{
    return GenMeshCube(1.0f, 1.0f, 1.0f);
}

template <> Shader Import()
{
    return {};
}

template <> Texture2D Import()
{
    constexpr int width = 64;
    constexpr int height = 64;
    ::Image image = ::GenImageColor(width, height, WHITE);
    ::Texture2D texture = ::LoadTextureFromImage(image);
    ::UnloadImage(image);
    return texture;
}

} // namespace Lumen::DefaultAssetImporter