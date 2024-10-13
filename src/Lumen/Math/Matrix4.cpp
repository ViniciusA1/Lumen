#include "Lumen/Math/Matrix4.hpp"
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Matrix4 Matrix4::Identity = Matrix4(1.0f);
const Matrix4 Matrix4::Zero = {};

Matrix4::Matrix4()
{
    m_Data.fill(0.0f);
}

Matrix4::Matrix4(float diagonal)
{
    m_Data.fill(0.0f);
    m_Data[0] = diagonal;
    m_Data[5] = diagonal;
    m_Data[10] = diagonal;
    m_Data[15] = diagonal;
}

Matrix4::Matrix4(const std::array<float, 16> &m_Data) : m_Data(m_Data)
{
}

float Matrix4::Determinant() const
{
    return m_Data[0] * (m_Data[5] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) -
                        m_Data[6] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) +
                        m_Data[7] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10])) -
           m_Data[1] * (m_Data[4] * (m_Data[10] * m_Data[15] - m_Data[14] * m_Data[11]) -
                        m_Data[6] * (m_Data[8] * m_Data[15] - m_Data[12] * m_Data[11]) +
                        m_Data[7] * (m_Data[8] * m_Data[14] - m_Data[12] * m_Data[10])) +
           m_Data[2] * (m_Data[4] * (m_Data[9] * m_Data[15] - m_Data[13] * m_Data[11]) -
                        m_Data[5] * (m_Data[8] * m_Data[15] - m_Data[12] * m_Data[11]) +
                        m_Data[7] * (m_Data[8] * m_Data[13] - m_Data[12] * m_Data[9])) -
           m_Data[3] * (m_Data[4] * (m_Data[9] * m_Data[14] - m_Data[13] * m_Data[10]) -
                        m_Data[5] * (m_Data[8] * m_Data[14] - m_Data[12] * m_Data[10]) +
                        m_Data[6] * (m_Data[8] * m_Data[13] - m_Data[12] * m_Data[9]));
}

Matrix4 Matrix4::Inverse() const
{
    Matrix4 inv;
    float det;
    int i;

    inv.m_Data[0] =
        m_Data[5] * m_Data[10] * m_Data[15] - m_Data[5] * m_Data[11] * m_Data[14] -
        m_Data[9] * m_Data[6] * m_Data[15] + m_Data[9] * m_Data[7] * m_Data[14] +
        m_Data[13] * m_Data[6] * m_Data[11] - m_Data[13] * m_Data[7] * m_Data[10];

    inv.m_Data[4] =
        -m_Data[4] * m_Data[10] * m_Data[15] + m_Data[4] * m_Data[11] * m_Data[14] +
        m_Data[8] * m_Data[6] * m_Data[15] - m_Data[8] * m_Data[7] * m_Data[14] -
        m_Data[12] * m_Data[6] * m_Data[11] + m_Data[12] * m_Data[7] * m_Data[10];

    inv.m_Data[8] =
        m_Data[4] * m_Data[9] * m_Data[15] - m_Data[4] * m_Data[11] * m_Data[13] -
        m_Data[8] * m_Data[5] * m_Data[15] + m_Data[8] * m_Data[7] * m_Data[13] +
        m_Data[12] * m_Data[5] * m_Data[11] - m_Data[12] * m_Data[7] * m_Data[9];

    inv.m_Data[12] =
        -m_Data[4] * m_Data[9] * m_Data[14] + m_Data[4] * m_Data[10] * m_Data[13] +
        m_Data[8] * m_Data[5] * m_Data[14] - m_Data[8] * m_Data[6] * m_Data[13] -
        m_Data[12] * m_Data[5] * m_Data[10] + m_Data[12] * m_Data[6] * m_Data[9];

    det = m_Data[0] * inv.m_Data[0] + m_Data[1] * inv.m_Data[4] +
          m_Data[2] * inv.m_Data[8] + m_Data[3] * inv.m_Data[12];

    if (det == 0)
        return Matrix4::Identity;

    det = 1.0f / det;

    for (i = 0; i < 16; i++)
        inv.m_Data[i] = inv.m_Data[i] * det;

    return inv;
}

bool Matrix4::IsIdentity() const
{
    static const Matrix4 identity = Matrix4::Identity;
    for (int i = 0; i < 16; ++i)
    {
        if (m_Data[i] != identity.m_Data[i])
            return false;
    }
    return true;
}

Vector3 Matrix4::LossyScale() const
{
    return {
        std::sqrt(m_Data[0] * m_Data[0] + m_Data[1] * m_Data[1] + m_Data[2] * m_Data[2]),
        std::sqrt(m_Data[4] * m_Data[4] + m_Data[5] * m_Data[5] + m_Data[6] * m_Data[6]),
        std::sqrt(m_Data[8] * m_Data[8] + m_Data[9] * m_Data[9] +
                  m_Data[10] * m_Data[10])};
}

Matrix4 Matrix4::Transpose() const
{
    Matrix4 result;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            result(row, col) = (*this)(col, row);
        }
    }
    return result;
}

Vector4 Matrix4::GetColumn(int index) const
{
    return {m_Data[index], m_Data[index + 4], m_Data[index + 8], m_Data[index + 12]};
}

Vector4 Matrix4::GetRow(int index) const
{
    return {m_Data[4 * index], m_Data[4 * index + 1], m_Data[4 * index + 2],
            m_Data[4 * index + 3]};
}

Vector3 Matrix4::GetPosition() const
{
    return {m_Data[12], m_Data[13], m_Data[14]};
}

Quaternion Matrix4::GetRotation() const
{
    Quaternion result = {0};
    ::Matrix mat = this->ToRaylib();

    float fourWSquaredMinus1 = mat.m0 + mat.m5 + mat.m10;
    float fourXSquaredMinus1 = mat.m0 - mat.m5 - mat.m10;
    float fourYSquaredMinus1 = mat.m5 - mat.m0 - mat.m10;
    float fourZSquaredMinus1 = mat.m10 - mat.m0 - mat.m5;

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
        result.x = (mat.m6 - mat.m9) * mult;
        result.y = (mat.m8 - mat.m2) * mult;
        result.z = (mat.m1 - mat.m4) * mult;
        break;
    case 1:
        result.x = biggestVal;
        result.w = (mat.m6 - mat.m9) * mult;
        result.y = (mat.m1 + mat.m4) * mult;
        result.z = (mat.m8 + mat.m2) * mult;
        break;
    case 2:
        result.y = biggestVal;
        result.w = (mat.m8 - mat.m2) * mult;
        result.x = (mat.m1 + mat.m4) * mult;
        result.z = (mat.m6 + mat.m9) * mult;
        break;
    case 3:
        result.z = biggestVal;
        result.w = (mat.m1 - mat.m4) * mult;
        result.x = (mat.m8 + mat.m2) * mult;
        result.y = (mat.m6 + mat.m9) * mult;
        break;
    }

    return result;
}

Vector3 Matrix4::GetScale() const
{
    return {Vector3(m_Data[0], m_Data[1], m_Data[2]).Magnitude(),
            Vector3(m_Data[4], m_Data[5], m_Data[6]).Magnitude(),
            Vector3(m_Data[8], m_Data[9], m_Data[10]).Magnitude()};
}

void Matrix4::SetColumn(int index, const Vector4 &column)
{
    m_Data[index] = column.x;
    m_Data[index + 4] = column.y;
    m_Data[index + 8] = column.z;
    m_Data[index + 12] = column.w;
}

void Matrix4::SetRow(int index, const Vector4 &row)
{
    m_Data[4 * index] = row.x;
    m_Data[4 * index + 1] = row.y;
    m_Data[4 * index + 2] = row.z;
    m_Data[4 * index + 3] = row.w;
}

void Matrix4::SetTransform(const Vector3 &translation, const Quaternion &rotation,
                           const Vector3 &scale)
{
    *this = Matrix4::Transform(translation, rotation, scale);
}

Matrix4 Matrix4::Frustum(float left, float right, float bottom, float top, float near,
                         float far)
{
    Matrix4 result;
    float rl = right - left;
    float tb = top - bottom;
    float fn = far - near;

    result.m_Data[0] = (2.0f * near) / rl;
    result.m_Data[5] = (2.0f * near) / tb;
    result.m_Data[8] = (right + left) / rl;
    result.m_Data[9] = (top + bottom) / tb;
    result.m_Data[10] = -(far + near) / fn;
    result.m_Data[11] = -1.0f;
    result.m_Data[14] = -(2.0f * far * near) / fn;
    result.m_Data[15] = 0.0f;

    return result;
}

Matrix4 Matrix4::LookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up)
{
    Vector3 forward = (eye - target).Normalized();
    Vector3 right = Vector3::Cross(up.Normalized(), forward).Normalized();
    Vector3 upVector = Vector3::Cross(forward, right);

    Matrix4 result;
    result.m_Data[0] = right.x;
    result.m_Data[1] = upVector.x;
    result.m_Data[2] = forward.x;
    result.m_Data[4] = right.y;
    result.m_Data[5] = upVector.y;
    result.m_Data[6] = forward.y;
    result.m_Data[8] = right.z;
    result.m_Data[9] = upVector.z;
    result.m_Data[10] = forward.z;
    result.m_Data[12] = -Vector3::Dot(right, eye);
    result.m_Data[13] = -Vector3::Dot(upVector, eye);
    result.m_Data[14] = -Vector3::Dot(forward, eye);

    return result;
}

Matrix4 Matrix4::Ortho(float left, float right, float bottom, float top, float near,
                       float far)
{
    Matrix4 result;
    result.m_Data[0] = 2.0f / (right - left);
    result.m_Data[5] = 2.0f / (top - bottom);
    result.m_Data[10] = -2.0f / (far - near);
    result.m_Data[12] = -(right + left) / (right - left);
    result.m_Data[13] = -(top + bottom) / (top - bottom);
    result.m_Data[14] = -(far + near) / (far - near);
    result.m_Data[15] = 1.0f;

    return result;
}

Matrix4 Matrix4::Perspective(float fov, float aspect, float near, float far)
{
    Matrix4 result;
    float tanHalfFov = tan(fov / 2.0f);
    result.m_Data[0] = 1.0f / (aspect * tanHalfFov);
    result.m_Data[5] = 1.0f / tanHalfFov;
    result.m_Data[10] = -(far + near) / (far - near);
    result.m_Data[11] = -1.0f;
    result.m_Data[14] = -(2.0f * far * near) / (far - near);

    return result;
}

Matrix4 Matrix4::Rotate(const Quaternion &q)
{
    Matrix4 result;
    float xx = q.x * q.x;
    float yy = q.y * q.y;
    float zz = q.z * q.z;
    float xy = q.x * q.y;
    float xz = q.x * q.z;
    float yz = q.y * q.z;
    float wx = q.w * q.x;
    float wy = q.w * q.y;
    float wz = q.w * q.z;

    result.m_Data[0] = 1.0f - 2.0f * (yy + zz);
    result.m_Data[1] = 2.0f * (xy - wz);
    result.m_Data[2] = 2.0f * (xz + wy);
    result.m_Data[4] = 2.0f * (xy + wz);
    result.m_Data[5] = 1.0f - 2.0f * (xx + zz);
    result.m_Data[6] = 2.0f * (yz - wx);
    result.m_Data[8] = 2.0f * (xz - wy);
    result.m_Data[9] = 2.0f * (yz + wx);
    result.m_Data[10] = 1.0f - 2.0f * (xx + yy);

    return result;
}

Matrix4 Matrix4::Scale(const Vector3 &scale)
{
    Matrix4 result;
    result.m_Data[0] = scale.x;
    result.m_Data[5] = scale.y;
    result.m_Data[10] = scale.z;
    result.m_Data[15] = 1.0f;
    return result;
}

Matrix4 Matrix4::Translate(const Vector3 &translation)
{
    Matrix4 result;
    result.m_Data[12] = translation.x;
    result.m_Data[13] = translation.y;
    result.m_Data[14] = translation.z;
    result.m_Data[15] = 1.0f;
    return result;
}

Matrix4 Matrix4::Transform(const Vector3 &translation, const Quaternion &rotation,
                           const Vector3 &scale)
{
    Matrix4 result = Matrix4::Rotate(rotation);
    result.m_Data[0] *= scale.x;
    result.m_Data[1] *= scale.x;
    result.m_Data[2] *= scale.x;
    result.m_Data[4] *= scale.y;
    result.m_Data[5] *= scale.y;
    result.m_Data[6] *= scale.y;
    result.m_Data[8] *= scale.z;
    result.m_Data[9] *= scale.z;
    result.m_Data[10] *= scale.z;

    result.m_Data[12] = translation.x;
    result.m_Data[13] = translation.y;
    result.m_Data[14] = translation.z;

    return result;
}

::Matrix Matrix4::ToRaylib() const
{
    return {m_Data[0],  m_Data[1],  m_Data[2],  m_Data[3], m_Data[4],  m_Data[5],
            m_Data[6],  m_Data[7],  m_Data[8],  m_Data[9], m_Data[10], m_Data[11],
            m_Data[12], m_Data[13], m_Data[14], m_Data[15]};
}

} // namespace Lumen