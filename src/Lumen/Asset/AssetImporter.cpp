#include "Lumen/Asset/AssetImporter.hpp"

namespace Lumen::AssetImporter
{

template <typename T> T Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    return {};
}

template <typename T> bool Export(const T &asset)
{
    return false;
}

} // namespace Lumen::AssetImporter
