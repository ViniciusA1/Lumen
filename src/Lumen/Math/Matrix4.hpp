#pragma once

#include <array>

struct Matrix;

namespace Lumen
{

class Vector3;
struct TransformComponent;

class Matrix4
{
public:
    static const Matrix4 Identity;
    static const Matrix4 Zero;

public:
    constexpr Matrix4();
    constexpr Matrix4(float diagonal);
    constexpr Matrix4(std::initializer_list<float> list);

    Matrix4(const ::Matrix &matrix);

    [[nodiscard]] constexpr float Determinant() const;
    [[nodiscard]] constexpr Matrix4 Inverse() const;
    [[nodiscard]] constexpr const std::array<float, 16> &ToFloat16() const;
    constexpr std::array<float, 16> &ToFloat16();
    [[nodiscard]] constexpr float Trace() const;
    [[nodiscard]] constexpr Matrix4 Transpose() const;

    static constexpr void DecomposeTransform(const Matrix4 &transform,
                                             Vector3 &translation, Vector3 &rotation,
                                             Vector3 &scale);
    static constexpr void DecomposeView(const Matrix4 &view, Vector3 &translation,
                                        Vector3 &target, Vector3 &up);
    static constexpr Matrix4 Frustum(float left, float right, float bottom, float top,
                                     float near, float far);
    static constexpr Matrix4 LookAt(const Vector3 &eye, const Vector3 &target,
                                    const Vector3 &up);
    static constexpr Matrix4 Ortho(float left, float right, float bottom, float top,
                                   float near, float far);
    static constexpr Matrix4 Perspective(float fovY, float aspect, float near, float far);
    static constexpr Matrix4 Rotate(const Vector3 &axis, float angle);
    static constexpr Matrix4 RotateX(float angle);
    static constexpr Matrix4 RotateY(float angle);
    static constexpr Matrix4 RotateZ(float angle);
    static constexpr Matrix4 RotateXYZ(const Vector3 &angle);
    static constexpr Matrix4 RotateZYX(const Vector3 &angle);
    static constexpr Matrix4 Scale(float x, float y, float z);
    static constexpr Matrix4 Scale(const Vector3 &scale);
    static constexpr Matrix4 Transform(const Vector3 &translation,
                                       const Vector3 &rotation, const Vector3 &scale);
    static constexpr Matrix4 Translate(float x, float y, float z);
    static constexpr Matrix4 Translate(const Vector3 &translation);

    constexpr float &operator[](std::size_t index);
    constexpr const float &operator[](std::size_t index) const;
    constexpr Matrix4 operator+(const Matrix4 &other) const;
    constexpr Matrix4 operator-(const Matrix4 &other) const;
    constexpr Matrix4 operator*(const Matrix4 &other) const;
    constexpr Matrix4 operator*(float scalar) const;
    operator ::Matrix() const;

private:
    std::array<float, 16> m;
};

} // namespace Lumen

#include "Lumen/Math/Matrix4.inl"