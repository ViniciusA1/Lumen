#include "Lumen/Meta/MetaData.hpp"
#include "Lumen/Meta/MetaType.hpp"

namespace Lumen
{

MetaData::MetaData(entt::meta_data data, MetaContext *ctx) : m_Data(data), m_Ctx(ctx)
{
}

bool MetaData::IsConst() const
{
    return m_Data.is_const();
}

bool MetaData::IsStatic() const
{
    return m_Data.is_static();
}

bool MetaData::IsValid() const
{
    return (bool)m_Data;
}

MetaAny MetaData::Get(const MetaAny &instance) const
{
    return {m_Data.get(instance.GetInternalAny())};
}

MetaType MetaData::GetType() const
{
    return {m_Data.type(), m_Ctx};
}

bool MetaData::Set(MetaAny &instance, const MetaAny &value) const
{
    return m_Data.set(instance.GetInternalAny(), value);
}

} // namespace Lumen