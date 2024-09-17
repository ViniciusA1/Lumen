#pragma once

struct Matrix;

namespace Lumen
{

class Matrix4
{
public:
    [[nodiscard]] ::Matrix ToRaylib() const;
};

} // namespace Lumen