#include "Lumen/Input/InputActionMap.hpp"

namespace Lumen
{

InputActionMap::InputActionMap(std::string name) : m_Name(std::move(name))
{
}

bool InputActionMap::IsEnabled() const
{
    return m_Enabled;
}

void InputActionMap::Enable()
{
    m_Enabled = true;
}

void InputActionMap::Disable()
{
    m_Enabled = false;
}

InputAction &InputActionMap::AddAction(const std::string &actionName)
{
    auto [it, inserted] = m_Actions.emplace(actionName, InputAction(actionName));
    return it->second;
}

void InputActionMap::RemoveAction(const std::string &actionName)
{
    m_Actions.erase(actionName);
}

std::optional<InputAction> InputActionMap::GetAction(const std::string &actionName)
{
    auto it = m_Actions.find(actionName);
    if (it != m_Actions.end())
        return it->second;

    return std::nullopt;
}

void InputActionMap::Update()
{
    if (!m_Enabled)
        return;

    for (auto &[_, action] : m_Actions)
        action.Update();
}

} // namespace Lumen