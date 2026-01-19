#pragma once

#include <cstdint>

namespace Lumen
{

struct PhysicsWorldCounters2D
{
    std::int32_t StaticBodyCount;
    std::int32_t BodyCount;
    std::int32_t ShapeCount;
    std::int32_t ContactCount;
    std::int32_t JointCount;
    std::int32_t IslandCount;
    std::int32_t StackUsed;
    std::int32_t StaticTreeHeight;
    std::int32_t TreeHeight;
    std::int32_t ByteCount;
    std::int32_t TaskCount;
};

} // namespace Lumen