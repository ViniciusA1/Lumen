#pragma once

#include "Lumen/Meta/MetaAny.hpp"

#include "entt/meta/meta.hpp"

namespace Lumen
{

class MetaType;

class MetaFunction
{
public:
    MetaFunction(entt::meta_func func);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] MetaType GetArgType(std::size_t index) const;
    [[nodiscard]] std::size_t GetArity() const;
    [[nodiscard]] MetaType GetReturnType() const;

    MetaAny Invoke(MetaAny &instance, MetaAny *args, std::size_t argc) const;

private:
    entt::meta_func m_Function;
};

} // namespace Lumen