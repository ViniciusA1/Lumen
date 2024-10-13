#pragma once

#include <string>

namespace Lumen
{

struct TagComponent
{
    std::string Tag;

    TagComponent() = default;
    TagComponent(std::string tag) : Tag(std::move(tag)) {}
};

} // namespace Lumen