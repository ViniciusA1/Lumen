#pragma once

#include "entt/meta/meta.hpp"

namespace Lumen
{

class MetaType;

class MetaAny
{
public:
    template <typename T> MetaAny(T &&value);
    MetaAny(entt::meta_any any);

    [[nodiscard]] bool IsAssociativeContainer() const;
    [[nodiscard]] bool IsSequenceContainer() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] entt::meta_any GetInternalAny() const;
    [[nodiscard]] MetaType GetType() const;

    [[nodiscard]] MetaAny Dereference() const;

    MetaAny AsRef();

    bool AllowCast(const MetaType &type);

    template <typename T> bool AllowCast();
    template <typename T> T Cast() const;
    template <typename T> T *TryCast();

private:
    entt::meta_any m_Any;
};

} // namespace Lumen