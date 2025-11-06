#pragma once

#include "Lumen/Input/InputAction.hpp"

#include <optional>

namespace Lumen
{

class InputActionMap
{
public:
    InputActionMap(std::string name);

    [[nodiscard]] bool IsEnabled() const;

    std::optional<InputAction> GetAction(const std::string &actionName);

    void Enable();
    void Disable();

    InputAction &AddAction(const std::string &actionName);
    void RemoveAction(const std::string &actionName);

    void Update();

private:
    std::string m_Name;
    std::unordered_map<std::string, InputAction> m_Actions;
    bool m_Enabled = false;
};

} // namespace Lumen