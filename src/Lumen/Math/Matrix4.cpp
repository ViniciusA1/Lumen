#include "Lumen/Math/Matrix4.hpp"

#include "raymath.h"

namespace Lumen
{

const Matrix4 Matrix4::Identity = Matrix4(1.0f);
const Matrix4 Matrix4::Zero = {};

Matrix4::Matrix4(const ::Matrix &matrix)
    : m({matrix.m0, matrix.m1, matrix.m2, matrix.m3, matrix.m4, matrix.m5, matrix.m6,
         matrix.m7, matrix.m8, matrix.m9, matrix.m10, matrix.m11, matrix.m12, matrix.m13,
         matrix.m14, matrix.m15})

{
}

Matrix4::operator ::Matrix() const
{
    return {m[0], m[1], m[2],  m[3],  m[4],  m[5],  m[6],  m[7],
            m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]};
}

} // namespace Lumen