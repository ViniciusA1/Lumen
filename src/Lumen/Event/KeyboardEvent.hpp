#pragma once

#include "Lumen/Input/KeyCode.hpp"

namespace Lumen
{

struct KeyPressedEvent
{
    KeyCode KeyCode;
    int RepeatCount;
};

struct KeyReleasedEvent
{
    KeyCode KeyCode;
};

} // namespace Lumen