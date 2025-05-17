#pragma once

#include "Lumen/Input/KeyCode.hpp"
#include "Lumen/Input/MouseCode.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

class Input
{
public:
    static bool IsKeyDown(KeyCode key);
    static bool IsKeyPressed(KeyCode key);
    static bool IsKeyUp(KeyCode key);

    static bool IsMouseButtonDown(MouseCode button);
    static bool IsMouseButtonPressed(MouseCode button);
    static bool IsMouseButtonUp(MouseCode button);

    static Vector2 GetMouseDelta();
    static Vector2 GetMousePosition();
    static float GetMouseWheelMove();

    static void SetMousePosition(int x, int y);

    static void PollEvents();
};

} // namespace Lumen