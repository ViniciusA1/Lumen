#include "Lumen/Input/Input.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterInput();

void RegisterInputAPI()
{
    RegisterInput();
}

static void RegisterInput()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Input>("Input")
        .StaticMethod("is_key_down", &Input::IsKeyDown)
        .StaticMethod("is_key_pressed", &Input::IsKeyPressed)
        .StaticMethod("is_key_pressed_repeat", &Input::IsKeyPressedRepeat)
        .StaticMethod("is_key_released", &Input::IsKeyReleased)
        .StaticMethod("is_key_up", &Input::IsKeyUp)
        .StaticMethod("get_char_pressed", &Input::GetCharPressed)
        .StaticMethod("get_key_pressed", &Input::GetKeyPressed)
        .StaticMethod("is_mouse_button_down", &Input::IsMouseButtonDown)
        .StaticMethod("is_mouse_button_pressed", &Input::IsMouseButtonPressed)
        .StaticMethod("is_mouse_button_released", &Input::IsMouseButtonReleased)
        .StaticMethod("is_mouse_button_up", &Input::IsMouseButtonUp)
        .StaticMethod("get_mouse_axis_movement", &Input::GetMouseAxisMovement)
        .StaticMethod("get_mouse_delta", &Input::GetMouseDelta)
        .StaticMethod("get_mouse_position", &Input::GetMousePosition)
        .StaticMethod("get_mouse_wheel_move", &Input::GetMouseWheelMove)
        .StaticMethod("get_mouse_wheel_move_v", &Input::GetMouseWheelMoveV)
        .StaticMethod("get_mouse_x", &Input::GetMouseX)
        .StaticMethod("get_mouse_y", &Input::GetMouseY)
        .StaticMethod("set_mouse_cursor", &Input::SetMouseCursor)
        .StaticMethod("set_mouse_offset",
                      static_cast<void (*)(Vector2)>(&Input::SetMouseOffset))
        .StaticMethod("set_mouse_position",
                      static_cast<void (*)(Vector2)>(&Input::SetMousePosition))
        .StaticMethod("set_mouse_scale",
                      static_cast<void (*)(Vector2)>(&Input::SetMouseScale))
        .StaticMethod("is_gamepad_available", &Input::IsGamepadAvailable)
        .StaticMethod("is_gamepad_button_down", &Input::IsGamepadButtonDown)
        .StaticMethod("is_gamepad_button_pressed", &Input::IsGamepadButtonPressed)
        .StaticMethod("is_gamepad_button_released", &Input::IsGamepadButtonReleased)
        .StaticMethod("is_gamepad_button_up", &Input::IsGamepadButtonUp)
        .StaticMethod("get_gamepad_axis_count", &Input::GetGamepadAxisCount)
        .StaticMethod("get_gamepad_axis_movement", &Input::GetGamepadAxisMovement)
        .StaticMethod("get_gamepad_button_pressed", &Input::GetGamepadButtonPressed)
        .StaticMethod("get_gamepad_name", &Input::GetGamepadName)
        .StaticMethod("set_gamepad_vibration", &Input::SetGamepadVibration);
}

} // namespace Lumen