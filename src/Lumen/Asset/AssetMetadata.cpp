#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen
{

AssetMetadata::AssetMetadata(class Path path, std::string name)
    : Path(std::move(path)), Name(std::move(name))
{
}

} // namespace Lumen