#include "Lumen/Meta/MetaType.hpp"

namespace Lumen
{

MetaType::MetaType(entt::meta_type type, MetaContext *ctx) : m_Type(std::move(type))
{
}

bool MetaType::IsValid() const
{
    return (bool)m_Type;
}

MetaData MetaType::GetData(MetaID id) const
{
    return m_Type.data(id);
}

MetaFunction MetaType::GetFunction(MetaID id) const
{
    return m_Type.func(id);
}

MetaID MetaType::GetId() const
{
    return m_Type.id();
}

entt::meta_type MetaType::GetInternalType() const
{
    return m_Type;
}

std::string_view MetaType::GetName() const
{
    return m_Type.info().name();
}

MetaAny MetaType::Construct() const
{
    return m_Type.construct();
}

} // namespace Lumen