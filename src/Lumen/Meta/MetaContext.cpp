#include "Lumen/Meta/MetaContext.hpp"

#include "entt/meta/node.hpp"

namespace Lumen
{

MetaContext::MetaContext() : m_Ctx()
{
}

void MetaContext::Swap(MetaContext &other)
{
    std::swap(m_Ctx, other.m_Ctx);
}

entt::meta_ctx &MetaContext::GetInternalCtx()
{
    return m_Ctx;
}

const entt::meta_ctx &MetaContext::GetInternalCtx() const
{
    return m_Ctx;
}

} // namespace Lumen