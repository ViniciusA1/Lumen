#pragma once

#include "Lumen/Meta/MetaAny.hpp"
#include "Lumen/Meta/MetaContext.hpp"

#include "entt/meta/meta.hpp"

namespace Lumen
{

class MetaType;

class MetaData
{
public:
    MetaData(entt::meta_data data, MetaContext *ctx = nullptr);

    [[nodiscard]] bool IsConst() const;
    [[nodiscard]] bool IsStatic() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] MetaAny Get(const MetaAny &instance) const;
    [[nodiscard]] MetaType GetType() const;

    bool Set(MetaAny &instance, const MetaAny &value) const;

private:
    entt::meta_data m_Data;
    MetaContext *m_Ctx;
};

} // namespace Lumen