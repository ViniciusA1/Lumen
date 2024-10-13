#include "Lumen/Math/Vector3.hpp"
#include <algorithm>
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Vector3 Vector3::Down = {0, -1, 0};
const Vector3 Vector3::Left = {-1, 0, 0};
const Vector3 Vector3::Right = {1, 0, 0};
const Vector3 Vector3::Up = {0, 1, 0};
const Vector3 Vector3::Back = {0, 0, -1};
const Vector3 Vector3::Forward = {0, 0, 1};
const Vector3 Vector3::Zero = {0, 0, 0};
const Vector3 Vector3::One = {1, 1, 1};

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

float Vector3::Magnitude() const
{
    return std::sqrt(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude() const
{
    return x * x + y * y + z * z;
}

Vector3 Vector3::Normalized() const
{
    float length = Magnitude();
    return (length > 0.0f) ? Vector3(x / length, y / length, z / length) : Vector3::Zero;
}

void Vector3::Normalize()
{
    float magnitude = Magnitude();
    if (magnitude > 0.0f)
    {
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }
}

float Vector3::Angle(const Vector3 &from, const Vector3 &to)
{
    float dot = Dot(from, to) / (from.Magnitude() * to.Magnitude());
    return std::acos(dot);
}

Vector3 Vector3::ClampMagnitude(const Vector3 &vector, float maxLength)
{
    if (vector.Magnitude() > maxLength)
    {
        return vector.Normalized() * maxLength;
    }
    return vector;
}

Vector3 Vector3::Cross(const Vector3 &v1, const Vector3 &v2)
{
    return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x};
}

float Vector3::Distance(const Vector3 &a, const Vector3 &b)
{
    return (a - b).Magnitude();
}

float Vector3::Dot(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 Vector3::Lerp(const Vector3 &a, const Vector3 &b, float t)
{
    return a + (b - a) * std::clamp(t, 0.0f, 1.0f);
}

Vector3 Vector3::LerpUnclamped(const Vector3 &a, const Vector3 &b, float t)
{
    return a + (b - a) * t;
}

Vector3 Vector3::Max(const Vector3 &v1, const Vector3 &v2)
{
    return {std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z)};
}

Vector3 Vector3::Min(const Vector3 &v1, const Vector3 &v2)
{
    return {std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z)};
}

Vector3 Vector3::MoveTowards(const Vector3 &current, const Vector3 &target,
                             float maxDistanceDelta)
{
    Vector3 direction = target - current;
    float distance = direction.Magnitude();
    if (distance <= maxDistanceDelta || distance == 0.0f)
        return target;
    return current + direction.Normalized() * maxDistanceDelta;
}

void Vector3::OrthoNormalize(Vector3 &normal, Vector3 &tangent)
{
    normal.Normalize();
    tangent = tangent - Project(tangent, normal);
    tangent.Normalize();
}

Vector3 Vector3::Project(const Vector3 &vector, const Vector3 &onNormal)
{
    float dot = Dot(vector, onNormal);
    float denominator = Dot(onNormal, onNormal);
    return onNormal * (dot / denominator);
}

Vector3 Vector3::ProjectOnPlane(const Vector3 &vector, const Vector3 &planeNormal)
{
    return vector - Project(vector, planeNormal);
}

Vector3 Vector3::Reflect(const Vector3 &direction, const Vector3 &normal)
{
    return direction - normal * 2.0f * Dot(direction, normal);
}

Vector3 Vector3::RotateTowards(const Vector3 &current, const Vector3 &target,
                               float maxRadiansDelta, float maxMagnitudeDelta)
{
    float angle = Angle(current, target);
    float t = std::min(1.0f, maxRadiansDelta / angle);
    return Lerp(current, target, t);
}

Vector3 Vector3::Scale(const Vector3 &a, const Vector3 &b)
{
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

float Vector3::SignedAngle(const Vector3 &from, const Vector3 &to, const Vector3 &axis)
{
    Vector3 cross = Cross(from, to);
    float angle = Angle(from, to);
    return Dot(cross, axis) < 0 ? -angle : angle;
}

Vector3 Vector3::Slerp(const Vector3 &a, const Vector3 &b, float t)
{
    float dot = Dot(a, b);
    dot = std::clamp(dot, -1.0f, 1.0f);
    float theta = std::acos(dot) * t;
    Vector3 relativeVec = (b - a * dot).Normalized();
    return a * std::cos(theta) + relativeVec * std::sin(theta);
}

Vector3 Vector3::SlerpUnclamped(const Vector3 &a, const Vector3 &b, float t)
{
    float dot = Dot(a, b);
    dot = std::clamp(dot, -1.0f, 1.0f);
    float theta = std::acos(dot) * t;
    Vector3 relativeVec = (b - a * dot).Normalized();
    return a * std::cos(theta) + relativeVec * std::sin(theta);
}

Vector3 Vector3::SmoothDamp(const Vector3 &current, const Vector3 &target,
                            Vector3 &currentVelocity, float smoothTime, float maxSpeed,
                            float deltaTime)
{
    float omega = 2.0f / smoothTime;
    float x = omega * deltaTime;
    float exp = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
    Vector3 change = current - target;
    Vector3 originalTarget = target;

    float maxChange = maxSpeed * smoothTime;
    change = ClampMagnitude(change, maxChange);
    Vector3 changedTarget = current - change;

    Vector3 tempVelocity = (currentVelocity + change * omega) * deltaTime;
    currentVelocity = (currentVelocity - tempVelocity * omega) * exp;

    Vector3 output = changedTarget + (change + tempVelocity) * exp;
    if (Dot(originalTarget - current, output - originalTarget) > 0.0f)
    {
        output = originalTarget;
        currentVelocity = (output - originalTarget) / deltaTime;
    }

    return output;
}

::Vector3 Vector3::ToRaylib() const
{
    return {x, y, z};
}

} // namespace Lumen