#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen
{

bool AssetMetadata::operator==(const AssetMetadata &other) const
{
    return Handle == other.Handle;
}

bool AssetMetadata::operator!=(const AssetMetadata &other) const
{
    return !(*this == other);
}

} // namespace Lumen