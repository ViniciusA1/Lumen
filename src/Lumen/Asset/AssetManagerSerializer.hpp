#pragma once

#include "Lumen/File/Path.hpp"
namespace Lumen
{

class AssetManagerSerializer
{
public:
    bool Serialize(const Path &path);
    bool Deserialize(const Path &path);
};

} // namespace Lumen