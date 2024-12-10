#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/UI/Style/Style.hpp"

namespace Lumen
{

class StyleSerializer
{
public:
    bool Serialize(const Path &path, const Style &style);
    bool Deserialize(const Path &path, Style &style);
};

} // namespace Lumen