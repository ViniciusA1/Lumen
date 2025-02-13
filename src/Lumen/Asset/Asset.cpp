#include "Lumen/Asset/Asset.hpp"

namespace Lumen
{

Asset::Asset(UUID uuid) : m_ID(uuid)
{
}

UUID Asset::GetID() const
{
    return m_ID;
}

} // namespace Lumen