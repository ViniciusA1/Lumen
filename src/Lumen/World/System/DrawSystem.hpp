#pragma once

#include "Lumen/World/System/System.hpp"

namespace Lumen
{

class DrawSystem : public System
{
public:
    DrawSystem(World &world, std::string name = "DrawSystem");

    virtual void OnDraw() = 0;
};

} // namespace Lumen