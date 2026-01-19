#include "Lumen/Meta/MetaRegistry.hpp"

namespace Lumen
{

MetaType MetaRegistry::Resolve(MetaID id)
{
    return entt::resolve(id);
}

MetaType MetaRegistry::Resolve(const MetaContext &ctx, MetaID id)
{
    return entt::resolve(ctx.GetInternalCtx(), id);
}

} // namespace Lumen