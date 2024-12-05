#include "Lumen/Math/Quaternion.hpp"
#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Vector3.hpp"
#include <algorithm>
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Quaternion Quaternion::Identity = {0.0f, 0.0f, 0.0f, 1.0f};

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Quaternion Quaternion::Inverted() const
{
    float lenSqr = x * x + y * y + z * z + w * w;

    if (lenSqr == 0.0f)
        return *this;

    return {-x / lenSqr, -y / lenSqr, -z / lenSqr, w / lenSqr};
}

float Quaternion::Length() const
{
    return sqrtf(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::Normalized() const
{
    float length = Length();
    return length > 0.0f ? *this / length : *this;
}

Matrix4 Quaternion::ToMatrix() const
{
    Matrix4 result = Matrix4::Identity;

    float a2 = x * x;
    float b2 = y * y;
    float c2 = z * z;
    float ac = x * z;
    float ab = x * y;
    float bc = y * z;
    float ad = w * x;
    float bd = w * y;
    float cd = w * z;

    result[0] = 1 - 2 * (b2 + c2);
    result[1] = 2 * (ab + cd);
    result[2] = 2 * (ac - bd);
    result[4] = 2 * (ab - cd);
    result[5] = 1 - 2 * (a2 + c2);
    result[6] = 2 * (bc + ad);
    result[8] = 2 * (ac + bd);
    result[9] = 2 * (bc - ad);
    result[10] = 1 - 2 * (a2 + b2);

    return result;
}

Vector3 Quaternion::ToEuler() const
{
    Vector3 result;

    float x0 = 2.0f * (w * x + y * z);
    float x1 = 1.0f - 2.0f * (x * x + y * y);
    result.x = atan2f(x0, x1);

    float y0 = 2.0f * (w * y - z * x);
    y0 = y0 > 1.0f ? 1.0f : y0;
    y0 = y0 < -1.0f ? -1.0f : y0;
    result.y = asinf(y0);

    float z0 = 2.0f * (w * z + x * y);
    float z1 = 1.0f - 2.0f * (y * y + z * z);
    result.z = atan2f(z0, z1);

    return result;
}

void Quaternion::ToAxisAngle(Vector3 &outAxis, float &outAngle)
{
    Quaternion q = *this;

    if (std::fabs(q.w) > 1.0f)
    {
        q = q.Normalized();
    }

    outAngle = 2.0f * std::acos(q.w);

    float den = std::sqrt(1.0f - q.w * q.w);
    if (den > EPSILON)
    {
        outAxis.x = q.x / den;
        outAxis.y = q.y / den;
        outAxis.z = q.z / den;
    }
    else
    {
        outAxis = Vector3(1.0f, 0.0f, 0.0f);
    }
}

Quaternion Quaternion::Transformed(const Matrix4 &mat) const
{
    return {mat[0] * x + mat[4] * y + mat[8] * z + mat[12] * w,
            mat[1] * x + mat[5] * y + mat[9] * z + mat[13] * w,
            mat[2] * x + mat[6] * y + mat[10] * z + mat[14] * w,
            mat[3] * x + mat[7] * y + mat[11] * z + mat[15] * w};
}

Quaternion Quaternion::FromAxisAngle(const Vector3 &axis, float angle)
{
    Vector3 normalizedAxis = axis.Normalized();
    angle *= 0.5f;

    float sinRes = sinf(angle);
    float cosRes = cosf(angle);

    Quaternion result(normalizedAxis.x * sinRes, normalizedAxis.y * sinRes,
                      normalizedAxis.z * sinRes, cosRes);

    return result.Normalized();
}

Quaternion Quaternion::FromEuler(float pitch, float yaw, float roll)
{
    float x0 = cosf(pitch * 0.5f);
    float x1 = sinf(pitch * 0.5f);
    float y0 = cosf(yaw * 0.5f);
    float y1 = sinf(yaw * 0.5f);
    float z0 = cosf(roll * 0.5f);
    float z1 = sinf(roll * 0.5f);

    return {x1 * y0 * z0 - x0 * y1 * z1, x0 * y1 * z0 + x1 * y0 * z1,
            x0 * y0 * z1 - x1 * y1 * z0, x0 * y0 * z0 + x1 * y1 * z1};
}

Quaternion Quaternion::FromMatrix(const Matrix4 &mat)
{
    Quaternion result;

    float fourWSquaredMinus1 = mat[0] + mat[5] + mat[10];
    float fourXSquaredMinus1 = mat[0] - mat[5] - mat[10];
    float fourYSquaredMinus1 = mat[5] - mat[0] - mat[10];
    float fourZSquaredMinus1 = mat[10] - mat[0] - mat[5];

    int biggestIndex = 0;
    float fourBiggestSquaredMinus1 = fourWSquaredMinus1;

    if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourXSquaredMinus1;
        biggestIndex = 1;
    }

    if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourYSquaredMinus1;
        biggestIndex = 2;
    }

    if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourZSquaredMinus1;
        biggestIndex = 3;
    }

    float biggestVal = sqrtf(fourBiggestSquaredMinus1 + 1.0f) * 0.5f;
    float mult = 0.25f / biggestVal;

    switch (biggestIndex)
    {
    case 0:
        result.w = biggestVal;
        result.x = (mat[6] - mat[9]) * mult;
        result.y = (mat[8] - mat[2]) * mult;
        result.z = (mat[1] - mat[4]) * mult;
        break;
    case 1:
        result.x = biggestVal;
        result.w = (mat[6] - mat[9]) * mult;
        result.y = (mat[1] + mat[4]) * mult;
        result.z = (mat[8] + mat[2]) * mult;
        break;
    case 2:
        result.y = biggestVal;
        result.w = (mat[8] - mat[2]) * mult;
        result.x = (mat[1] + mat[4]) * mult;
        result.z = (mat[6] + mat[9]) * mult;
        break;
    case 3:
        result.z = biggestVal;
        result.w = (mat[1] - mat[4]) * mult;
        result.x = (mat[8] + mat[2]) * mult;
        result.y = (mat[6] + mat[9]) * mult;
        break;
    }

    return result;
}

Quaternion Quaternion::FromVector3ToVector3(const Vector3 &from, const Vector3 &to)
{
    float cos2Theta = Vector3::Dot(from, to);
    Vector3 cross = Vector3::Cross(from, to);

    Quaternion result(cross.x, cross.y, cross.z, 1.0f + cos2Theta);

    return result.Normalized();
}

Quaternion Quaternion::Lerp(const Quaternion &q1, const Quaternion &q2, float amount)
{
    return q1 + (q2 - q1) * std::clamp(amount, 0.0f, 1.0f);
}

Quaternion Quaternion::Nlerp(const Quaternion &q1, const Quaternion &q2, float amount)
{
    return Lerp(q1, q2, amount).Normalized();
}

Quaternion Quaternion::Slerp(const Quaternion &q1, const Quaternion &q2, float amount)
{
    Quaternion result;

    float cosHalfTheta = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

    Quaternion q2Modified = q2;
    if (cosHalfTheta < 0)
    {
        q2Modified.x = -q2.x;
        q2Modified.y = -q2.y;
        q2Modified.z = -q2.z;
        q2Modified.w = -q2.w;
        cosHalfTheta = -cosHalfTheta;
    }

    if (fabs(cosHalfTheta) >= 1.0f)
    {
        result = q1;
    }
    else if (cosHalfTheta > 0.95f)
    {
        result = Nlerp(q1, q2Modified, amount);
    }
    else
    {
        float halfTheta = acos(cosHalfTheta);
        float sinHalfTheta = sqrt(1.0f - cosHalfTheta * cosHalfTheta);

        if (fabs(sinHalfTheta) < EPSILON)
        {
            result.x = (q1.x * 0.5f + q2Modified.x * 0.5f);
            result.y = (q1.y * 0.5f + q2Modified.y * 0.5f);
            result.z = (q1.z * 0.5f + q2Modified.z * 0.5f);
            result.w = (q1.w * 0.5f + q2Modified.w * 0.5f);
        }
        else
        {
            float ratioA = sin((1 - amount) * halfTheta) / sinHalfTheta;
            float ratioB = sin(amount * halfTheta) / sinHalfTheta;

            result.x = (q1.x * ratioA + q2Modified.x * ratioB);
            result.y = (q1.y * ratioA + q2Modified.y * ratioB);
            result.z = (q1.z * ratioA + q2Modified.z * ratioB);
            result.w = (q1.w * ratioA + q2Modified.w * ratioB);
        }
    }

    return result;
}

Quaternion operator+(const Quaternion &lhs, const Quaternion &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

Quaternion operator+(const Quaternion &lhs, float value)
{
    return {lhs.x + value, lhs.y + value, lhs.z + value, lhs.w + value};
}

Quaternion operator-(const Quaternion &lhs, const Quaternion &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

Quaternion operator-(const Quaternion &lhs, float value)
{
    return {lhs.x - value, lhs.y - value, lhs.z - value, lhs.w - value};
}

Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs)
{
    return {lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
            lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
            lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z};
}

Quaternion operator*(const Quaternion &lhs, float scalar)
{
    return {lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar};
}

Quaternion operator*(float scalar, const Quaternion &rhs)
{
    return rhs * scalar;
}

Quaternion operator/(const Quaternion &lhs, const Quaternion &rhs)
{
    return lhs * rhs.Inverted();
}

Quaternion &operator+=(Quaternion &lhs, const Quaternion &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

Quaternion &operator-=(Quaternion &lhs, const Quaternion &rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

Quaternion &operator*=(Quaternion &lhs, float scalar)
{
    lhs = lhs * scalar;
    return lhs;
}

Quaternion &operator/=(Quaternion &lhs, float scalar)
{
    lhs = lhs * (1.0f / scalar);
    return lhs;
}

bool operator==(const Quaternion &lhs, const Quaternion &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

bool operator!=(const Quaternion &lhs, const Quaternion &rhs)
{
    return !(lhs == rhs);
}

Quaternion::operator ::Vector4() const
{
    return {x, y, z, w};
}

} // namespace Lumen