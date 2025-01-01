#pragma once

#include "Lumen/Math/Vector2.hpp"

struct Rectangle;

namespace Lumen
{

class Rectangle
{
public:
    float x;
    float y;
    float Width;
    float Height;

    Rectangle(float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f);
    Rectangle(const Vector2 &position, const Vector2 &size);
    Rectangle(const ::Rectangle rectangle);

    operator ::Rectangle() const;
};

} // namespace Lumen