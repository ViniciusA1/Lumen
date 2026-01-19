#pragma once

#include "Lumen/System/UUID.hpp"

#include <vector>

namespace Lumen
{

struct ChildrenComponent
{
    std::vector<UUID> ChildrenID;
};

} // namespace Lumen