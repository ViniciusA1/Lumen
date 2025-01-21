#pragma once

#include <string>

namespace Lumen
{

struct TagComponent
{
    std::string Name;

    TagComponent() = default;
    TagComponent(std::string name) : Name(std::move(name)) {}
};

} // namespace Lumen