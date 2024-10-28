#pragma once

struct Rectangle;

namespace Lumen
{

class Rectangle
{
public:
    float X;
    float Y;
    float Width;
    float Height;

    Rectangle(float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f);

    operator ::Rectangle() const;
};

} // namespace Lumen