#include "Lumen/Input/InputBinding.hpp"
#include "Lumen/Input/Input.hpp"
#include "Lumen/Input/KeyCode.hpp"

namespace Lumen
{

int InputBinding::GetCode() const
{
    return m_Code;
}

InputDevice InputBinding::GetDevice() const
{
    return m_Device;
}

std::string InputBinding::GetName() const
{
    return m_Name;
}

InputValue InputBinding::GetValue() const
{
    switch (m_Device)
    {
    case InputDevice::Keyboard:
        return GetValueKeyboard();
    case InputDevice::Mouse:
        return GetValueMouse();
    case InputDevice::Gamepad:
        return GetValueGamepad();
    };

    return {};
}

bool InputBinding::operator==(const InputBinding &other) const
{
    return m_Name == other.m_Name && m_Device == other.m_Device &&
           m_Code == other.m_Code && m_IsComposite == other.m_IsComposite;
}

InputValue InputBinding::GetValueKeyboard() const
{
    auto key = static_cast<KeyCode>(m_Code);
    InputValue value{Input::IsKeyDown(key)};
    return value;
}

InputValue InputBinding::GetValueMouse() const
{
    InputValue value;

    return value;
}

InputValue InputBinding::GetValueGamepad() const
{
    InputValue value;

    return value;
}

} // namespace Lumen