#include "Lumen/Input/InputAction.hpp"

namespace Lumen
{

InputAction::InputAction(std::string name) : m_Name(std::move(name))
{
}

const std::vector<InputBinding> &InputAction::GetBindings() const
{
    return m_Bindings;
}

const InputValue &InputAction::GetCurrentValue() const
{
    return m_Value;
}

const std::string &InputAction::GetName() const
{
    return m_Name;
}

InputActionPhase InputAction::GetPhase() const
{
    return m_Phase;
}

InputActionType InputAction::GetType() const
{
    return m_Type;
}

void InputAction::SetPhaseCallback(InputActionPhase phase,
                                   const InputActionCallback &callback)
{
    m_Callbacks[phase] = callback;
}

void InputAction::SetPhase(InputActionPhase phase)
{
    m_Phase = phase;
}

void InputAction::SetType(InputActionType type)
{
    m_Type = type;
}

void InputAction::AddBinding(const InputBinding &binding)
{
    m_Bindings.push_back(binding);
}

void InputAction::RemoveBinding(const InputBinding &binding)
{
    m_Bindings.erase(std::remove(m_Bindings.begin(), m_Bindings.end(), binding),
                     m_Bindings.end());
}

void InputAction::Update()
{
    if (m_Bindings.empty() || m_Phase == InputActionPhase::Disabled)
        return;

    InputValue newValue;

    for (const auto &binding : m_Bindings)
    {
    }

    switch (m_Type)
    {
    case InputActionType::Button:
        UpdateButton();
        break;
    case InputActionType::Value:
        UpdateValue();
        break;
    case InputActionType::PassThrough:
        UpdatePassThrough();
        break;
    }
}

void InputAction::UpdateButton()
{
}

void InputAction::UpdateValue()
{
}

void InputAction::UpdatePassThrough()
{
}

void InputAction::OnPhase()
{
    if (m_Callbacks.contains(m_Phase))
        m_Callbacks[m_Phase](m_Value);
}

} // namespace Lumen