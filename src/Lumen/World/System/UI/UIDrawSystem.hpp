#pragma once

#include "Lumen/World/System/DrawSystem.hpp"

namespace Lumen
{

class UIDrawSystem : public DrawSystem
{
public:
    UIDrawSystem(World &world);

    void OnDraw() final;
};

} // namespace Lumen