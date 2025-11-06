#include "Lumen/Input/InputComposite.hpp"

namespace Lumen
{

const std::vector<InputBinding> &InputComposite::GetBindings() const
{
    return m_Bindings;
}

std::vector<InputBinding> &InputComposite::GetBindings()
{
    return m_Bindings;
}

std::string InputComposite::GetName() const
{
    return m_Name;
}

bool InputComposite::operator==(const InputComposite &other) const
{
    return m_Name == other.m_Name && m_Bindings == other.m_Bindings;
}

} // namespace Lumen