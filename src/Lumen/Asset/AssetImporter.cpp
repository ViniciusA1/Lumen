#include "Lumen/Asset/AssetImporter.hpp"

namespace Lumen::AssetImporter
{

template <typename T> Ref<T> Import(const AssetMetadata &metadata)
{
    return nullptr;
}

template <typename T> bool Export(const Ref<T> &asset)
{
    return false;
}

} // namespace Lumen::AssetImporter
