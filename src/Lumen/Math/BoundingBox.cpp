#include "Lumen/Math/BoundingBox.hpp"

#include "raylib.h"

namespace Lumen
{

BoundingBox::BoundingBox(const ::BoundingBox &box) : Min(box.min), Max(box.max)
{
}

BoundingBox::operator ::BoundingBox() const
{
    return {Min, Max};
}

} // namespace Lumen