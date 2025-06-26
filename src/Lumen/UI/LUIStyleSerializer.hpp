#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/UI/Module/LUIStyle.hpp"

namespace Lumen
{

class LUIStyleSerializer
{
public:
    bool Serialize(const Path &path, const LUI::Style &style);
    bool Deserialize(const Path &path, LUI::Style &style);
};

} // namespace Lumen