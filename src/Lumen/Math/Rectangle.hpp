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

public:
    constexpr Rectangle(float x = 0.0f, float y = 0.0f, float width = 0.0f,
                        float height = 0.0f);
    constexpr Rectangle(float x = 0.0f, float y = 0.0f,
                        const Vector2 &size = {0.0f, 0.0f});
    constexpr Rectangle(const Vector2 &position = {0.0f, 0.0f}, float width = 0.0f,
                        float height = 0.0f);
    constexpr Rectangle(const Vector2 &position, const Vector2 &size);

    Rectangle(const TransformComponent &transform);
    Rectangle(const struct ::Rectangle &rectangle);

    [[nodiscard]] constexpr bool Contains(const Vector2 &point) const;
    [[nodiscard]] constexpr bool Intersects(const Rectangle &other) const;

    [[nodiscard]] constexpr Vector2 GetCenter() const;
    [[nodiscard]] constexpr Vector2 GetPosition() const;
    [[nodiscard]] constexpr Vector2 GetSize() const;

    constexpr void SetPosition(const Vector2 &position);
    constexpr void SetSize(const Vector2 &size);

    operator struct ::Rectangle() const;
};

} // namespace Lumen

#include "Lumen/Math/Rectangle.inl"