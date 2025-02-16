#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/Scene/Entity/Component/ComponentBase.hpp"

namespace Lumen
{

struct ModelRendererComponent : public ComponentBase
{
    UUID Model = 0;
};

} // namespace Lumen