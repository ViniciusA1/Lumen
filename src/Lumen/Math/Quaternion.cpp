#include "Lumen/Math/Quaternion.hpp"
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Quaternion Quaternion::Identity = {1.0f, 0.0f, 0.0f, 0.0f};

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Vector3 Quaternion::EulerAngles() const
{
    Vector3 eulerAngles;

    float sinr_cosp = 2.0f * (w * x + y * z);
    float cosr_cosp = 1.0f - 2.0f * (x * x + y * y);
    eulerAngles.x = atan2(sinr_cosp, cosr_cosp);

    float sinp = 2.0f * (w * y - z * x);
    if (fabs(sinp) >= 1.0f)
        eulerAngles.y = copysign(PI / 2, sinp);
    else
        eulerAngles.y = asin(sinp);

    float siny_cosp = 2.0f * (w * z + x * y);
    float cosy_cosp = 1.0f - 2.0f * (y * y + z * z);
    eulerAngles.z = atan2(siny_cosp, cosy_cosp);

    eulerAngles = eulerAngles * (180.0f / PI);

    return eulerAngles;
}

Quaternion Quaternion::Normalized() const
{
    Quaternion q = *this;
    return Quaternion::Normalize(q);
}

void Quaternion::Set(float newX, float newY, float newZ, float newW)
{
    x = newX;
    y = newY;
    z = newZ;
    w = newW;
}

void Quaternion::SetFromToRotation(const Vector3 &fromDirection,
                                   const Vector3 &toDirection)
{
    *this = FromToRotation(fromDirection, toDirection);
}

void Quaternion::SetLookRotation(const Vector3 &forward, const Vector3 &upwards)
{
    *this = LookRotation(forward, upwards);
}

void Quaternion::ToAngleAxis(float &angle, Vector3 &axis) const
{
    Quaternion q = Normalized();
    angle = 2.0f * acos(q.w) * (180.0f / PI);
    float s = sqrt(1.0f - q.w * q.w);
    if (s < 0.001f)
    {
        axis = {1, 0, 0};
    }
    else
    {
        axis = {q.x / s, q.y / s, q.z / s};
    }
}

float Quaternion::Angle(const Quaternion &a, const Quaternion &b)
{
    return acos(fmin(fabs(Dot(a, b)), 1.0f)) * 2.0f * (180.0f / PI);
}

Quaternion Quaternion::AngleAxis(float angle, const Vector3 &axis)
{
    float rad = angle * (PI / 180.0f);
    float s = sin(rad / 2.0f);
    return {axis.x * s, axis.y * s, axis.z * s, cos(rad / 2.0f)};
}

float Quaternion::Dot(const Quaternion &a, const Quaternion &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
    float halfX = x * (PI / 180.0f) / 2.0f;
    float halfY = y * (PI / 180.0f) / 2.0f;
    float halfZ = z * (PI / 180.0f) / 2.0f;

    float sinX = sin(halfX);
    float cosX = cos(halfX);
    float sinY = sin(halfY);
    float cosY = cos(halfY);
    float sinZ = sin(halfZ);
    float cosZ = cos(halfZ);

    return {
        cosY * cosX * sinZ + sinY * sinX * cosZ, sinY * cosX * cosZ - cosY * sinX * sinZ,
        cosY * sinX * cosZ + sinY * cosX * sinZ, cosY * cosX * cosZ - sinY * sinX * sinZ};
}

Quaternion Quaternion::FromToRotation(const Vector3 &fromDirection,
                                      const Vector3 &toDirection)
{
    Vector3 cross = Vector3::Cross(fromDirection.Normalized(), toDirection.Normalized());
    float dot = Vector3::Dot(fromDirection.Normalized(), toDirection.Normalized());
    float s = sqrt((1 + dot) * 2);
    return {cross.x / s, cross.y / s, cross.z / s, s / 2.0f};
}

Quaternion Quaternion::Inverse(const Quaternion &rotation)
{
    return {-rotation.x, -rotation.y, -rotation.z, rotation.w};
}

Quaternion Quaternion::Lerp(const Quaternion &a, const Quaternion &b, float t)
{
    return Normalize(Quaternion(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y),
                                a.z + t * (b.z - a.z), a.w + t * (b.w - a.w)));
}

Quaternion Quaternion::LerpUnclamped(const Quaternion &a, const Quaternion &b, float t)
{
    return Normalize(Quaternion(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y),
                                a.z + t * (b.z - a.z), a.w + t * (b.w - a.w)));
}

Quaternion Quaternion::LookRotation(const Vector3 &forward, const Vector3 &upwards)
{
    Vector3 f = forward.Normalized();
    Vector3 r = Vector3::Cross(upwards.Normalized(), f).Normalized();
    Vector3 u = Vector3::Cross(f, r);

    float w = sqrt(1.0f + r.x + u.y + f.z) * 0.5f;
    float w4Recip = 1.0f / (4.0f * w);

    return {(u.z - f.y) * w4Recip, (f.x - r.z) * w4Recip, (r.y - u.x) * w4Recip, w};
}

Quaternion Quaternion::Normalize(const Quaternion &q)
{
    float mag = sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    if (mag > 0.0f)
    {
        float invMag = 1.0f / mag;
        return {q.x * invMag, q.y * invMag, q.z * invMag, q.w * invMag};
    }
    return q;
}

Quaternion Quaternion::RotateTowards(const Quaternion &from, const Quaternion &to,
                                     float maxAngle)
{
    float angle = Angle(from, to);
    if (angle == 0)
        return to;
    return Slerp(from, to, fmin(1.0f, maxAngle / angle));
}

Quaternion Quaternion::Slerp(const Quaternion &a, const Quaternion &b, float t)
{
    float dot = Dot(a, b);

    if (dot < 0.0f)
    {
        dot = -dot;
    }

    float theta = acos(fmin(fabs(dot), 1.0f)) * t;

    Quaternion relative;
    relative.x = b.x - a.x * dot;
    relative.y = b.y - a.y * dot;
    relative.z = b.z - a.z * dot;
    relative.w = b.w - a.w * dot;
    Quaternion::Normalize(relative);

    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    Quaternion result;
    result.x = a.x * cosTheta + relative.x * sinTheta;
    result.y = a.y * cosTheta + relative.y * sinTheta;
    result.z = a.z * cosTheta + relative.z * sinTheta;
    result.w = a.w * cosTheta + relative.w * sinTheta;

    return result;
}

Quaternion Quaternion::SlerpUnclamped(const Quaternion &a, const Quaternion &b, float t)
{
    float dot = Dot(a, b);

    if (dot < 0.0f)
    {
        dot = -dot;
    }

    float theta = acos(fmin(fabs(dot), 1.0f)) * t;

    Quaternion relative;
    relative.x = b.x - a.x * dot;
    relative.y = b.y - a.y * dot;
    relative.z = b.z - a.z * dot;
    relative.w = b.w - a.w * dot;
    Quaternion::Normalize(relative);

    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    Quaternion result;
    result.x = a.x * cosTheta + relative.x * sinTheta;
    result.y = a.y * cosTheta + relative.y * sinTheta;
    result.z = a.z * cosTheta + relative.z * sinTheta;
    result.w = a.w * cosTheta + relative.w * sinTheta;

    return result;
}

::Vector4 Quaternion::ToRaylib() const
{
    return {x, y, z, w};
}

} // namespace Lumen