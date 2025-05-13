#include "Lumen/Graphics/ImageFactory.hpp"

#include "raylib.h"

namespace Lumen
{

Image ImageFactory::CreateCellular(const Vector2 &size, int tileSize)
{
    return ::GenImageCellular(size.x, size.y, tileSize);
}

Image ImageFactory::CreateChecked(const Vector2 &size, int checksX, int checksY,
                                  Color col1, Color col2)
{
    return ::GenImageChecked(size.x, size.y, checksX, checksY, col1, col2);
}

Image ImageFactory::CreateColor(const Vector2 &size, Color color)
{
    return ::GenImageColor(size.x, size.y, color);
}

Image ImageFactory::CreateGradientLinear(const Vector2 &size, int direction, Color start,
                                         Color end)
{
    return ::GenImageGradientLinear(size.x, size.y, direction, start, end);
}

Image ImageFactory::CreateGradientRadial(const Vector2 &size, float density, Color inner,
                                         Color outer)
{
    return ::GenImageGradientRadial(size.x, size.y, density, inner, outer);
}

Image ImageFactory::CreateGradientSquare(const Vector2 &size, float density, Color inner,
                                         Color outer)
{
    return ::GenImageGradientSquare(size.x, size.y, density, inner, outer);
}

Image ImageFactory::CreatePerlinNoise(const Vector2 &size, int offsetX, int offsetY,
                                      float scale)
{
    return ::GenImagePerlinNoise(size.x, size.y, offsetX, offsetY, scale);
}

Image ImageFactory::CreateText(const Vector2 &size, const Vector2 &pos,
                               const std::string &text, float fontSize, Color textColor)
{
    RenderTexture2D target = ::LoadRenderTexture(size.x, size.y);
    ::BeginTextureMode(target);
    ::ClearBackground(Color::Blank);
    ::DrawText(text.c_str(), pos.x, pos.y, fontSize, textColor);
    ::EndTextureMode();

    ::Image raylibImage = ::LoadImageFromTexture(target.texture);
    ::UnloadRenderTexture(target);

    return raylibImage;
}

Image ImageFactory::CreateWhiteNoise(const Vector2 &size, float factor)
{
    return ::GenImageWhiteNoise(size.x, size.y, factor);
}

} // namespace Lumen