#include "Lumen/Asset/Asset.hpp"

namespace Lumen
{

Asset::Asset(const AssetHandle &handle) : m_Handle(handle)
{
}

AssetHandle Asset::GetHandle() const
{
    return m_Handle;
}

} // namespace Lumen