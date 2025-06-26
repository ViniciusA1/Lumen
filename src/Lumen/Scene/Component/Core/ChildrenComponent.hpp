#pragma once

#include "Lumen/Core/UUID.hpp"

#include <vector>

namespace Lumen
{

struct ChildrenComponent
{
    std::vector<UUID> ChildrenID;
};

} // namespace Lumen