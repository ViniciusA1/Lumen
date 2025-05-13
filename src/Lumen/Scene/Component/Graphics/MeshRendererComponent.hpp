#pragma once

#include "Lumen/Core/UUID.hpp"

namespace Lumen
{

struct MeshRendererComponent
{
    UUID Mesh = 0;
    UUID Model = 0;
};

} // namespace Lumen