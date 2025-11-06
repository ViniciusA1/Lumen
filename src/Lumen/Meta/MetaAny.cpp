#include "Lumen/Meta/MetaAny.hpp"
#include "Lumen/Meta/MetaType.hpp"

namespace Lumen
{

MetaAny::MetaAny(entt::meta_any any) : m_Any(std::move(any))
{
}

bool MetaAny::IsAssociativeContainer() const
{
    return m_Any.type().is_associative_container();
}

bool MetaAny::IsSequenceContainer() const
{
    return m_Any.type().is_sequence_container();
}

bool MetaAny::IsValid() const
{
    return (bool)m_Any;
}

entt::meta_any MetaAny::GetInternalAny() const
{
    return m_Any;
}

MetaType MetaAny::GetType() const
{
    return {m_Any.type()};
}

MetaAny MetaAny::Dereference() const
{
    return *m_Any;
}

MetaAny MetaAny::AsRef()
{
    return m_Any.as_ref();
}

bool MetaAny::AllowCast(const MetaType &type)
{
    return m_Any.allow_cast(type.GetInternalType());
}

} // namespace Lumen