#include "Lumen/Core/Action.hpp"

namespace Lumen
{

bool Action::IsBound() const
{
    return !m_Actions.empty();
}

void Action::Clear()
{
    m_Actions.clear();
}

void Action::Invoke() const
{
    for (const auto &func : m_Actions)
    {
        func();
    }
}

void Action::operator()() const
{
    Invoke();
}

} // namespace Lumen