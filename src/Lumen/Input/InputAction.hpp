#pragma once

#include "Lumen/Input/InputActionPhase.hpp"
#include "Lumen/Input/InputActionType.hpp"
#include "Lumen/Input/InputBinding.hpp"
#include "Lumen/Input/InputValue.hpp"
#include "Lumen/System/Function.hpp"


#include <string>
#include <vector>

namespace Lumen
{

class InputAction
{
public:
    using InputActionCallback = Function<void(const InputValue &)>;

public:
    InputAction(std::string name);

    [[nodiscard]] const std::vector<InputBinding> &GetBindings() const;
    [[nodiscard]] const InputValue &GetCurrentValue() const;
    [[nodiscard]] const std::string &GetName() const;
    [[nodiscard]] InputActionPhase GetPhase() const;
    [[nodiscard]] InputActionType GetType() const;

    void SetPhaseCallback(InputActionPhase phase, const InputActionCallback &callback);
    void SetPhase(InputActionPhase phase);
    void SetType(InputActionType type);

    void AddBinding(const InputBinding &binding);
    void RemoveBinding(const InputBinding &binding);

    void Update();

private:
    void UpdateButton();
    void UpdateValue();
    void UpdatePassThrough();

    void OnPhase();

private:
    std::string m_Name;
    InputActionType m_Type = InputActionType::Button;
    InputActionPhase m_Phase = InputActionPhase::Waiting;
    InputValue m_Value;
    InputValueType m_ControlType = InputValueType::Bool;
    std::vector<InputBinding> m_Bindings;
    std::unordered_map<InputActionPhase, InputActionCallback> m_Callbacks;
};

} // namespace Lumen