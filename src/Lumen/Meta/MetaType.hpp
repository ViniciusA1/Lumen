#pragma once

#include "Lumen/Meta/MetaContext.hpp"
#include "Lumen/Meta/MetaData.hpp"
#include "Lumen/Meta/MetaFunction.hpp"
#include "Lumen/Meta/MetaID.hpp"

#include "entt/meta/meta.hpp"

namespace Lumen
{

class MetaType
{
public:
    MetaType(entt::meta_type type, MetaContext *ctx = nullptr);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] MetaData GetData(MetaID id) const;
    [[nodiscard]] MetaFunction GetFunction(MetaID id) const;
    [[nodiscard]] MetaID GetId() const;
    [[nodiscard]] entt::meta_type GetInternalType() const;
    [[nodiscard]] std::string_view GetName() const;

    [[nodiscard]] MetaAny Construct() const;

    template <typename Func> void IterateBases(Func &&func) const;

private:
    entt::meta_type m_Type;
};

} // namespace Lumen

#include "Lumen/Meta/MetaType.inl"