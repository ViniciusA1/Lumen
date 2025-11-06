#pragma once

#include "Lumen/Meta/MetaRegistry.hpp"

#include "entt/meta/resolve.hpp"

namespace Lumen
{

template <typename T> MetaType MetaRegistry::Resolve()
{
    return entt::resolve<T>();
}

template <typename T> MetaType MetaRegistry::Resolve(const MetaContext &ctx)
{
    return entt::resolve<T>(ctx.GetInternalCtx());
}

} // namespace Lumen