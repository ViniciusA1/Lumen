#pragma once

#include "Lumen/Math/Quaternion.hpp"
#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"
#include <array>

struct Matrix;

namespace Lumen
{

class Matrix4
{
public:
    static const Matrix4 Identity;
    static const Matrix4 Zero;

public:
    Matrix4();
    Matrix4(float diagonal);
    Matrix4(const std::array<float, 16> &data);

    inline float &operator()(int row, int col);
    inline const float &operator()(int row, int col) const;
    inline Matrix4 operator*(const Matrix4 &other) const;
    operator ::Matrix() const;

    [[nodiscard]] float Determinant() const;
    [[nodiscard]] Matrix4 Inverse() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] Vector3 LossyScale() const;
    [[nodiscard]] Matrix4 Transpose() const;
    [[nodiscard]] Vector4 GetColumn(int index) const;
    [[nodiscard]] Vector4 GetRow(int index) const;
    [[nodiscard]] Vector3 GetPosition() const;
    [[nodiscard]] Quaternion GetRotation() const;
    [[nodiscard]] Vector3 GetScale() const;
    void SetColumn(int index, const Vector4 &column);
    void SetRow(int index, const Vector4 &row);
    void SetTransform(const Vector3 &translation, const Quaternion &rotation,
                      const Vector3 &scale);

    static Matrix4 Frustum(float left, float right, float bottom, float top, float near,
                           float far);
    static Matrix4 LookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up);
    static Matrix4 Ortho(float left, float right, float bottom, float top, float near,
                         float far);
    static Matrix4 Perspective(float fov, float aspect, float near, float far);
    static Matrix4 Rotate(const Quaternion &q);
    static Matrix4 Scale(const Vector3 &scale);
    static Matrix4 Translate(const Vector3 &translation);
    static Matrix4 Transform(const Vector3 &translation, const Quaternion &rotation,
                             const Vector3 &scale);

private:
    std::array<float, 16> m_Data;
};

float &Matrix4::operator()(int row, int col)
{
    return m_Data[row * 4 + col];
}

const float &Matrix4::operator()(int row, int col) const
{
    return m_Data[row * 4 + col];
}

Matrix4 Matrix4::operator*(const Matrix4 &other) const
{
    Matrix4 result;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            result(row, col) =
                (*this)(row, 0) * other(0, col) + (*this)(row, 1) * other(1, col) +
                (*this)(row, 2) * other(2, col) + (*this)(row, 3) * other(3, col);
        }
    }
    return result;
}

} // namespace Lumen