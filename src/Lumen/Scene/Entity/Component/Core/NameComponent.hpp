#pragma once

#include <string>

namespace Lumen
{

struct NameComponent
{
    std::string Name;

    NameComponent() = default;
    NameComponent(std::string name) : Name(std::move(name)) {}
};

} // namespace Lumen