#include "Lumen/Meta/MetaFunction.hpp"
#include "Lumen/Meta/MetaType.hpp"

namespace Lumen
{

MetaFunction::MetaFunction(entt::meta_func func) : m_Function(func)
{
}

bool MetaFunction::IsValid() const
{
    return static_cast<bool>(m_Function);
}

MetaType MetaFunction::GetArgType(std::size_t index) const
{
    return m_Function.arg(index);
}

std::size_t MetaFunction::GetArity() const
{
    return m_Function.arity();
}

MetaType MetaFunction::GetReturnType() const
{
    return m_Function.ret();
}

MetaAny MetaFunction::Invoke(MetaAny &instance, MetaAny *args, std::size_t argc) const
{
    return m_Function.invoke(instance, args, argc);
}

} // namespace Lumen