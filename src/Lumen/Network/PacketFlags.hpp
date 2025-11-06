#pragma once

#include "Lumen/Meta/Enum.hpp"

namespace Lumen
{

enum class PacketFlags
{
    Reliable = 1 << 0,
    Unsequenced = 1 << 1,
    NoAllocate = 1 << 2,
    UnreliableFragment = 1 << 3,
    Unthrottled = 1 << 4,
    Sent = 1 << 8,
};

ENUM_ENABLE_BITMASK(PacketFlags)

} // namespace Lumen