#pragma once

#include "Lumen/Input/InputDevice.hpp"
#include "Lumen/Input/InputValue.hpp"

#include <string>

namespace Lumen
{

class InputBinding
{
public:
    InputBinding();

    [[nodiscard]] int GetCode() const;
    [[nodiscard]] InputDevice GetDevice() const;
    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] InputValue GetValue() const;

    bool operator==(const InputBinding &other) const;

private:
    [[nodiscard]] InputValue GetValueKeyboard() const;
    [[nodiscard]] InputValue GetValueMouse() const;
    [[nodiscard]] InputValue GetValueGamepad() const;

private:
    std::string m_Name;
    InputDevice m_Device;
    int m_Code;
    bool m_IsComposite;
};

} // namespace Lumen