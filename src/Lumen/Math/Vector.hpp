#pragma once

struct Vector2;
struct Vector3;
struct Vector4;

namespace Lumen
{

class Vector2
{
public:
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f);

    [[nodiscard]] ::Vector2 ToRaylib() const;
};

class Vector3
{
public:
    float x, y, z, w;

    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    [[nodiscard]] ::Vector3 ToRaylib() const;
};

class Vector4
{
public:
    float x, y, z, w;

    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);

    [[nodiscard]] ::Vector4 ToRaylib() const;
};

} // namespace Lumen