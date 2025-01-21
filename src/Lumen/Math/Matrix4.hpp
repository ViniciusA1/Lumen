#pragma once

#include <array>

struct Matrix;

namespace Lumen
{

class Vector3;

class Matrix4
{
public:
    static const Matrix4 Identity;
    static const Matrix4 Zero;

public:
    Matrix4();
    Matrix4(float diagonal);
    Matrix4(std::initializer_list<float> list);
    Matrix4(const ::Matrix &matrix);

    [[nodiscard]] float Determinant() const;
    [[nodiscard]] Matrix4 Inverse() const;
    [[nodiscard]] const std::array<float, 16> &ToFloat16() const;
    std::array<float, 16> &ToFloat16();
    [[nodiscard]] float Trace() const;
    [[nodiscard]] Matrix4 Transpose() const;

    static void DecomposeTransform(const Matrix4 &transform, Vector3 &translation,
                                   Vector3 &rotation, Vector3 &scale);
    static void DecomposeView(const Matrix4 &view, Vector3 &translation, Vector3 &target,
                              Vector3 &up);
    static Matrix4 Frustum(float left, float right, float bottom, float top, float near,
                           float far);
    static Matrix4 LookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up);
    static Matrix4 Ortho(float left, float right, float bottom, float top, float near,
                         float far);
    static Matrix4 Perspective(float fovY, float aspect, float near, float far);
    static Matrix4 Rotate(const Vector3 &axis, float angle);
    static Matrix4 RotateX(float angle);
    static Matrix4 RotateY(float angle);
    static Matrix4 RotateZ(float angle);
    static Matrix4 RotateXYZ(const Vector3 &angle);
    static Matrix4 RotateZYX(const Vector3 &angle);
    static Matrix4 Scale(float x, float y, float z);
    static Matrix4 Transform(const Vector3 &translation, const Vector3 &rotation,
                             const Vector3 &scale);
    static Matrix4 Translate(float x, float y, float z);

    float &operator[](std::size_t index);
    const float &operator[](std::size_t index) const;
    Matrix4 operator+(const Matrix4 &other) const;
    Matrix4 operator-(const Matrix4 &other) const;
    Matrix4 operator*(const Matrix4 &other) const;
    Matrix4 operator*(float scalar) const;
    operator ::Matrix() const;

private:
    std::array<float, 16> m;
};

} // namespace Lumen