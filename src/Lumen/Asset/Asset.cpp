#include "Lumen/Asset/Asset.hpp"

namespace Lumen
{

Asset::Asset(AssetMetadata metadata) : m_Metadata(std::move(metadata))
{
}

} // namespace Lumen