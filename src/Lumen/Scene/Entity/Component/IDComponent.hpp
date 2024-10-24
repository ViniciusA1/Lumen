#pragma once

#include "Lumen/Core/UUID.hpp"

namespace Lumen
{

struct IDComponent
{
    UUID ID;

    IDComponent() = default;
    IDComponent(const UUID &uuid) : ID(uuid) {}
};

} // namespace Lumen