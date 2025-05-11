#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/UI/LUIStyle.hpp"

namespace Lumen
{

class LUIStyleSerializer
{
public:
    bool Serialize(const Path &path, const LUIStyle &style);
    bool Deserialize(const Path &path, LUIStyle &style);
};

} // namespace Lumen