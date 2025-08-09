#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Scene/Component/UI/UIComponentState.hpp"

namespace Lumen
{

struct UIComponentBase
{
    UIComponentState State = UIComponentState::Idle;
    std::array<Color, static_cast<int>(UIComponentState::Count)> Colors = {
        Color::White,
        Color::LightGray,
        Color::DarkGray,
        Color::DarkGray,
    };
};

} // namespace Lumen