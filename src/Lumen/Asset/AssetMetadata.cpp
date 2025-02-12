#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen
{

AssetMetadata::AssetMetadata(UUID uuid, std::string name, class Path path)
    : ID(uuid), Name(std::move(name)), Path(std::move(path))
{
}

AssetMetadata::AssetMetadata(std::string name, class Path path)
    : AssetMetadata(UUID(), std::move(name), std::move(path))
{
}

} // namespace Lumen