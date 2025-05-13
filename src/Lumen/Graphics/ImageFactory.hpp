#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Math/Vector2.hpp"

#include <string>

namespace Lumen
{

class ImageFactory
{
public:
    ImageFactory() = delete;

public:
    static Image CreateCellular(const Vector2 &size, int tileSize);

    static Image CreateChecked(const Vector2 &size, int checksX, int checksY, Color col1,
                               Color col2);

    static Image CreateColor(const Vector2 &size, Color color);

    static Image CreateGradientLinear(const Vector2 &size, int direction, Color start,
                                      Color end);

    static Image CreateGradientRadial(const Vector2 &size, float density, Color inner,
                                      Color outer);

    static Image CreateGradientSquare(const Vector2 &size, float density, Color inner,
                                      Color outer);

    static Image CreatePerlinNoise(const Vector2 &size, int offsetX, int offsetY,
                                   float scale);

    static Image CreateText(const Vector2 &size, const Vector2 &pos,
                            const std::string &text, float fontSize, Color textColor);

    static Image CreateWhiteNoise(const Vector2 &size, float factor);
};

} // namespace Lumen