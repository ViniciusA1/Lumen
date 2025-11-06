#pragma once

namespace Lumen
{

enum class InputActionPhase
{
    Disabled,
    Waiting,
    Started,
    Performed,
    Canceled
};

} // namespace Lumen