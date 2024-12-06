#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Vector3.hpp"
#include <cmath>
#include <raymath.h>

namespace Lumen
{

const Matrix4 Matrix4::Identity = Matrix4(1.0f);
const Matrix4 Matrix4::Zero = {};

Matrix4::Matrix4()
{
    m.fill(0.0f);
}

Matrix4::Matrix4(float diagonal)
{
    m.fill(0.0f);
    m[0] = diagonal;
    m[5] = diagonal;
    m[10] = diagonal;
    m[15] = diagonal;
}

Matrix4::Matrix4(std::initializer_list<float> list)
{
    if (list.size() == 16)
    {
        std::copy(list.begin(), list.end(), m.begin());
    }
    else
    {
        m.fill(0.0f);
    }
}

Matrix4::Matrix4(const ::Matrix &matrix)
    : m({matrix.m0, matrix.m4, matrix.m8, matrix.m12, matrix.m1, matrix.m5, matrix.m9,
         matrix.m13, matrix.m2, matrix.m6, matrix.m10, matrix.m14, matrix.m3, matrix.m7,
         matrix.m11, matrix.m15})
{
}

float Matrix4::Determinant() const
{
    float a00 = m[0], a01 = m[1], a02 = m[2], a03 = m[3];
    float a10 = m[4], a11 = m[5], a12 = m[6], a13 = m[7];
    float a20 = m[8], a21 = m[9], a22 = m[10], a23 = m[11];
    float a30 = m[12], a31 = m[13], a32 = m[14], a33 = m[15];

    return a30 * a21 * a12 * a03 - a20 * a31 * a12 * a03 - a30 * a11 * a22 * a03 +
           a10 * a31 * a22 * a03 + a20 * a11 * a32 * a03 - a10 * a21 * a32 * a03 -
           a30 * a21 * a02 * a13 + a20 * a31 * a02 * a13 + a30 * a01 * a22 * a13 -
           a00 * a31 * a22 * a13 - a20 * a01 * a32 * a13 + a00 * a21 * a32 * a13 +
           a30 * a11 * a02 * a23 - a10 * a31 * a02 * a23 - a30 * a01 * a12 * a23 +
           a00 * a31 * a12 * a23 + a10 * a01 * a32 * a23 - a00 * a11 * a32 * a23 -
           a20 * a11 * a02 * a33 + a10 * a21 * a02 * a33 + a20 * a01 * a12 * a33 -
           a00 * a21 * a12 * a33 - a10 * a01 * a22 * a33 + a00 * a11 * a22 * a33;
}

Matrix4 Matrix4::Inverse() const
{
    Matrix4 inverse;

    float a00 = m[0], a01 = m[1], a02 = m[2], a03 = m[3];
    float a10 = m[4], a11 = m[5], a12 = m[6], a13 = m[7];
    float a20 = m[8], a21 = m[9], a22 = m[10], a23 = m[11];
    float a30 = m[12], a31 = m[13], a32 = m[14], a33 = m[15];

    float b00 = a00 * a11 - a01 * a10;
    float b01 = a00 * a12 - a02 * a10;
    float b02 = a00 * a13 - a03 * a10;
    float b03 = a01 * a12 - a02 * a11;
    float b04 = a01 * a13 - a03 * a11;
    float b05 = a02 * a13 - a03 * a12;
    float b06 = a20 * a31 - a21 * a30;
    float b07 = a20 * a32 - a22 * a30;
    float b08 = a20 * a33 - a23 * a30;
    float b09 = a21 * a32 - a22 * a31;
    float b10 = a21 * a33 - a23 * a31;
    float b11 = a22 * a33 - a23 * a32;

    float invDet =
        1.0f / (b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06);

    inverse[0] = (a11 * b11 - a12 * b10 + a13 * b09) * invDet;
    inverse[1] = (-a01 * b11 + a02 * b10 - a03 * b09) * invDet;
    inverse[2] = (a31 * b05 - a32 * b04 + a33 * b03) * invDet;
    inverse[3] = (-a21 * b05 + a22 * b04 - a23 * b03) * invDet;
    inverse[4] = (-a10 * b11 + a12 * b08 - a13 * b07) * invDet;
    inverse[5] = (a00 * b11 - a02 * b08 + a03 * b07) * invDet;
    inverse[6] = (-a30 * b05 + a32 * b02 - a33 * b01) * invDet;
    inverse[7] = (a20 * b05 - a22 * b02 + a23 * b01) * invDet;
    inverse[8] = (a10 * b10 - a11 * b08 + a13 * b06) * invDet;
    inverse[9] = (-a00 * b10 + a01 * b08 - a03 * b06) * invDet;
    inverse[10] = (a30 * b04 - a31 * b02 + a33 * b00) * invDet;
    inverse[11] = (-a20 * b04 + a21 * b02 - a23 * b00) * invDet;
    inverse[12] = (-a10 * b09 + a11 * b07 - a12 * b06) * invDet;
    inverse[13] = (a00 * b09 - a01 * b07 + a02 * b06) * invDet;
    inverse[14] = (-a30 * b03 + a31 * b01 - a32 * b00) * invDet;
    inverse[15] = (a20 * b03 - a21 * b01 + a22 * b00) * invDet;

    return inverse;
}

float Matrix4::Trace() const
{
    return m[0] + m[5] + m[10] + m[15];
}

Matrix4 Matrix4::Transpose() const
{
    Matrix4 transpose;

    transpose[0] = m[0];
    transpose[1] = m[4];
    transpose[2] = m[8];
    transpose[3] = m[12];
    transpose[4] = m[1];
    transpose[5] = m[5];
    transpose[6] = m[9];
    transpose[7] = m[13];
    transpose[8] = m[2];
    transpose[9] = m[6];
    transpose[10] = m[10];
    transpose[11] = m[14];
    transpose[12] = m[3];
    transpose[13] = m[7];
    transpose[14] = m[11];
    transpose[15] = m[15];

    return transpose;
}

Matrix4 Matrix4::Frustum(float left, float right, float bottom, float top, float near,
                         float far)
{
    Matrix4 result;

    float rl = right - left;
    float tb = top - bottom;
    float fn = far - near;

    result[0] = (near * 2.0f) / rl;
    result[5] = (near * 2.0f) / tb;
    result[8] = (right + left) / rl;
    result[9] = (top + bottom) / tb;
    result[10] = -(far + near) / fn;
    result[11] = -1.0f;
    result[14] = -(far * near * 2.0f) / fn;

    return result;
}

Matrix4 Matrix4::LookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up)
{
    Matrix4 result;

    float length = 0.0f;
    float ilength = 0.0f;

    Vector3 vz = (eye - target).Normalized();
    Vector3 vx = Vector3::Cross(up, vz).Normalized();
    Vector3 vy = Vector3::Cross(vz, vx);

    result[0] = vx.x;
    result[1] = vy.x;
    result[2] = vz.x;
    result[4] = vx.y;
    result[5] = vy.y;
    result[6] = vz.y;
    result[8] = vx.z;
    result[9] = vy.z;
    result[10] = vz.z;
    result[12] = Vector3::Dot(vx, eye);
    result[13] = Vector3::Dot(vy, eye);
    result[14] = Vector3::Dot(vz, eye);
    result[15] = 1.0f;

    return result;
}

Matrix4 Matrix4::Ortho(float left, float right, float bottom, float top, float near,
                       float far)
{
    Matrix4 result;

    float rl = (right - left);
    float tb = (top - bottom);
    float fn = (far - near);

    result[0] = 2.0f / rl;
    result[5] = 2.0f / tb;
    result[10] = -2.0f / fn;
    result[12] = -(left + right) / rl;
    result[13] = -(top + bottom) / tb;
    result[14] = -(far + near) / fn;
    result[15] = 1.0f;

    return result;
}

Matrix4 Matrix4::Perspective(float fovY, float aspect, float near, float far)
{
    double top = near * std::tan(fovY * 0.5);
    double right = top * aspect;

    return Frustum(-right, right, -top, top, near, far);
}

Matrix4 Matrix4::Rotate(const Vector3 &axis, float angle)
{
    Matrix4 result;

    Vector3 normalized = axis.Normalized();
    float x = normalized.x, y = normalized.y, z = normalized.z;

    float sinres = std::sin(angle);
    float cosres = std::cos(angle);
    float t = 1.0f - cosres;

    result[0] = x * x * t + cosres;
    result[1] = y * x * t + z * sinres;
    result[2] = z * x * t - y * sinres;

    result[4] = x * y * t - z * sinres;
    result[5] = y * y * t + cosres;
    result[6] = z * y * t + x * sinres;

    result[8] = x * z * t + y * sinres;
    result[9] = y * z * t - x * sinres;
    result[10] = z * z * t + cosres;

    result[15] = 1.0f;

    return result;
}

Matrix4 Matrix4::RotateX(float angle)
{
    Matrix4 result = Matrix4::Identity;

    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);

    result[5] = cosAngle;
    result[6] = sinAngle;
    result[9] = -sinAngle;
    result[10] = cosAngle;

    return result;
}

Matrix4 Matrix4::RotateY(float angle)
{
    Matrix4 result = Matrix4::Identity;

    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);

    result[0] = cosAngle;
    result[2] = -sinAngle;
    result[8] = sinAngle;
    result[10] = cosAngle;

    return result;
}

Matrix4 Matrix4::RotateZ(float angle)
{
    Matrix4 result = Matrix4::Identity;

    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);

    result[0] = cosAngle;
    result[1] = sinAngle;
    result[4] = -sinAngle;
    result[5] = cosAngle;

    return result;
}

Matrix4 Matrix4::RotateXYZ(const Vector3 &angle)
{
    Matrix4 result = Matrix4::Identity;

    float cosz = std::cos(-angle.z);
    float sinz = std::sin(-angle.z);
    float cosy = std::cos(-angle.y);
    float siny = std::sin(-angle.y);
    float cosx = std::cos(-angle.x);
    float sinx = std::sin(-angle.x);

    result[0] = cosz * cosy;
    result[1] = (cosz * siny * sinx) - (sinz * cosx);
    result[2] = (cosz * siny * cosx) + (sinz * sinx);

    result[4] = sinz * cosy;
    result[5] = (sinz * siny * sinx) + (cosz * cosx);
    result[6] = (sinz * siny * cosx) - (cosz * sinx);

    result[8] = -siny;
    result[9] = cosy * sinx;
    result[10] = cosy * cosx;

    return result;
}

Matrix4 Matrix4::RotateZYX(const Vector3 &angle)
{
    Matrix4 result;

    float cz = std::cos(angle.z);
    float sz = std::sin(angle.z);
    float cy = std::cos(angle.y);
    float sy = std::sin(angle.y);
    float cx = std::cos(angle.x);
    float sx = std::sin(angle.x);

    result[0] = cz * cy;
    result[4] = cz * sy * sx - cx * sz;
    result[8] = sz * sx + cz * cx * sy;

    result[1] = cy * sz;
    result[5] = cz * cx + sz * sy * sx;
    result[9] = cx * sz * sy - cz * sx;

    result[2] = -sy;
    result[6] = cy * sx;
    result[10] = cy * cx;

    result[15] = 1;

    return result;
}

Matrix4 Matrix4::Scale(float x, float y, float z)
{
    return Matrix4({x, 0.0f, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f, z, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f});
}

Matrix4 Matrix4::Translate(float x, float y, float z)
{
    return Matrix4({1.0f, 0.0f, 0.0f, x, 0.0f, 1.0f, 0.0f, y, 0.0f, 0.0f, 1.0f, z, 0.0f,
                    0.0f, 0.0f, 1.0f});
}

float &Matrix4::operator[](std::size_t index)
{
    return m[index];
}

const float &Matrix4::operator[](std::size_t index) const
{
    return m[index];
}

Matrix4 Matrix4::operator+(const Matrix4 &other) const
{
    Matrix4 result;

    for (size_t i = 0; i < 16; i++)
        result[i] = m[i] + other[i];

    return result;
}

Matrix4 Matrix4::operator-(const Matrix4 &other) const
{
    Matrix4 result;

    for (size_t i = 0; i < 16; i++)
        result[i] = m[i] - other[i];

    return result;
}

Matrix4 Matrix4::operator*(const Matrix4 &other) const
{
    Matrix4 result;

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            for (int k = 0; k < 4; k++)
            {
                result[row * 4 + col] += m[row * 4 + k] * other[k * 4 + col];
            }
        }
    }

    return result;
}

Matrix4 Matrix4::operator*(float scalar) const
{
    Matrix4 result;

    for (size_t i = 0; i < 16; ++i)
        result[i] = m[i] * scalar;

    return result;
}

Matrix4::operator ::Matrix() const
{
    return {m[0], m[1], m[2],  m[3],  m[4],  m[5],  m[6],  m[7],
            m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]};
}

} // namespace Lumen