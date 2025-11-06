#pragma once

#include "entt/meta/context.hpp"

namespace Lumen
{

class MetaContext
{
public:
    MetaContext();
    MetaContext(const MetaContext &) = delete;
    MetaContext &operator=(const MetaContext &) = delete;

    void Swap(MetaContext &other);

    entt::meta_ctx &GetInternalCtx();
    [[nodiscard]] const entt::meta_ctx &GetInternalCtx() const;

private:
    entt::meta_ctx m_Ctx;
};

} // namespace Lumen