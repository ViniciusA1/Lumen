#pragma once

#include "Lumen/Input/GamepadCode.hpp"
#include "Lumen/Input/KeyCode.hpp"
#include "Lumen/Input/MouseCode.hpp"
#include "Lumen/Input/MouseCursor.hpp"
#include "Lumen/Math/Vector2.hpp"

#include <string>

namespace Lumen
{

class Input
{
public:
    static bool IsKeyDown(KeyCode key);
    static bool IsKeyPressed(KeyCode key);
    static bool IsKeyPressedRepeat(KeyCode key);
    static bool IsKeyReleased(KeyCode key);
    static bool IsKeyUp(KeyCode key);

    static int GetCharPressed();
    static KeyCode GetKeyPressed();

    static bool IsMouseButtonDown(MouseCode button);
    static bool IsMouseButtonPressed(MouseCode button);
    static bool IsMouseButtonReleased(MouseCode button);
    static bool IsMouseButtonUp(MouseCode button);

    static float GetMouseAxisMovement(MouseCode axis);
    static Vector2 GetMouseDelta();
    static Vector2 GetMousePosition();
    static float GetMouseWheelMove();
    static Vector2 GetMouseWheelMoveV();
    static int GetMouseX();
    static int GetMouseY();

    static void SetMouseCursor(MouseCursor cursor);
    static void SetMouseOffset(int offsetX, int offsetY);
    static void SetMouseOffset(Vector2 offset);
    static void SetMousePosition(int x, int y);
    static void SetMousePosition(Vector2 position);
    static void SetMouseScale(float scaleX, float scaleY);
    static void SetMouseScale(Vector2 scale);

    static bool IsGamepadAvailable(int gamepad);
    static bool IsGamepadButtonDown(int gamepad, GamepadCode button);
    static bool IsGamepadButtonPressed(int gamepad, GamepadCode button);
    static bool IsGamepadButtonReleased(int gamepad, GamepadCode button);
    static bool IsGamepadButtonUp(int gamepad, GamepadCode button);

    static int GetGamepadAxisCount(int gamepad);
    static float GetGamepadAxisMovement(int gamepad, GamepadCode axis);
    static GamepadCode GetGamepadButtonPressed();
    static std::string GetGamepadName(int gamepad);

    static void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor,
                                    float duration);

    static void PollEvents();
};

} // namespace Lumen