#include "Lumen/Math/Vector4.hpp"
#include <algorithm>
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Vector4 Vector4::Zero = {0, 0, 0, 0};
const Vector4 Vector4::One = {1, 1, 1, 1};

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

float Vector4::Magnitude() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::SqrMagnitude() const
{
    return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::Normalized() const
{
    float length = Magnitude();
    return (length > 0.0f) ? Vector4(x / length, y / length, z / length, w / length)
                           : Vector4::Zero;
}

void Vector4::Normalize()
{
    float magnitude = std::sqrt(x * x + y * y + z * z + w * w);
    if (magnitude > 0.0f)
    {
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
        w /= magnitude;
    }
}

float Vector4::Distance(const Vector4 &a, const Vector4 &b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
                     (a.z - b.z) * (a.z - b.z) + (a.w - b.w) * (a.w - b.w));
}

float Vector4::Dot(const Vector4 &a, const Vector4 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vector4 Vector4::Lerp(const Vector4 &a, const Vector4 &b, float t)
{
    return a + (b - a) * std::clamp(t, 0.0f, 1.0f);
}

Vector4 Vector4::LerpUnclamped(const Vector4 &a, const Vector4 &b, float t)
{
    return a + (b - a) * t;
}

Vector4 Vector4::Max(const Vector4 &a, const Vector4 &b)
{
    return {std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z),
            std::max(a.w, b.w)};
}

Vector4 Vector4::Min(const Vector4 &a, const Vector4 &b)
{
    return {std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z),
            std::min(a.w, b.w)};
}

Vector4 Vector4::MoveTowards(const Vector4 &current, const Vector4 &target,
                             float maxDistanceDelta)
{
    Vector4 delta = target - current;
    float distance = delta.Magnitude();
    if (distance <= maxDistanceDelta || distance == 0.0f)
    {
        return target;
    }
    return current + delta / distance * maxDistanceDelta;
}

Vector4 Vector4::Normalize(const Vector4 &vec)
{
    float magnitude =
        std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
    if (magnitude > 0.0f)
    {
        return {vec.x / magnitude, vec.y / magnitude, vec.z / magnitude,
                vec.w / magnitude};
    }
    return {0.0f, 0.0f, 0.0f, 0.0f};
}

Vector4 Vector4::Project(const Vector4 &a, const Vector4 &b)
{
    float dotProduct = Dot(a, b);
    float magnitudeSquared = Dot(b, b);
    return magnitudeSquared != 0 ? b * (dotProduct / magnitudeSquared)
                                 : Vector4(0, 0, 0, 0);
}

Vector4 Vector4::Scale(const Vector4 &a, const Vector4 &b)
{
    return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

Vector4::operator ::Vector4() const
{
    return {x, y, z, w};
}

} // namespace Lumen