#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct MeshRendererComponent : public ComponentBase
{
    UUID Mesh = 0;
    UUID Model = 0;
};

} // namespace Lumen