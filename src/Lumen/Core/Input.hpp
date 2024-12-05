#pragma once

#include "Lumen/Core/InputCode.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

class Input
{
public:
    static bool GetKeyPressed(KeyCode key);
    static bool GetKeyDown(KeyCode key);
    static bool GetKeyUp(KeyCode key);

    static bool GetMouseButton(MouseCode button);
    static bool GetMouseButtonDown(MouseCode button);
    static bool GetMouseButtonUp(MouseCode button);

    static Vector2 GetMouseDelta();
    static Vector2 GetMousePosition();
    static float GetMouseWheelMove();

    static void PollEvents();
};

} // namespace Lumen