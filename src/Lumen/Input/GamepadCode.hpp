#pragma once

namespace Lumen
{

enum class GamepadCode
{
    ButtonUnknown = 0,
    ButtonLeftFaceUp,
    ButtonLeftFaceRight,
    ButtonLeftFaceDown,
    ButtonLeftFaceLeft,
    ButtonRightFaceUp,
    ButtonRightFaceRight,
    ButtonRightFaceDown,
    ButtonRightFaceLeft,
    ButtonLeftTrigger1,
    ButtonLeftTrigger2,
    ButtonRightTrigger1,
    ButtonRightTrigger2,
    ButtonMiddleLeft,
    ButtonMiddle,
    ButtonMiddleRight,
    ButtonLeftThumb,
    ButtonRightThumb,

    AxisLeftX = 1000,
    AxisLeftY,
    AxisRightX,
    AxisRightY,
    AxisLeftTrigger,
    AxisRightTrigger
};

} // namespace Lumen