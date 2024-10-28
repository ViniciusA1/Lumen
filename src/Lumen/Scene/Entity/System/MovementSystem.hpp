#pragma once

#include "Lumen/Scene/Entity/System/System.hpp"

namespace Lumen
{

class MovementSystem : public System
{
public:
    MovementSystem(World &world);

    void OnUpdate() override;
};

} // namespace Lumen