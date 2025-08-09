#pragma once

#include "Lumen/Scene/Component/UI/UIComponentBase.hpp"

namespace Lumen
{

struct CheckboxComponent : public UIComponentBase
{
    bool Value = false;
};

} // namespace Lumen