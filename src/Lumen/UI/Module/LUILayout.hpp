#pragma once

#include "Lumen/Math/Vector2.hpp"

namespace Lumen::LUI
{

enum class LayoutType
{
    None,
    Grid,
    Horizontal,
    Property,
    Vertical,
};

struct LayoutData
{
    LayoutType Type = LayoutType::None;
    Vector2 ItemSize;
    Vector2 Spacing;
    int Columns = 1;
    int CurrentColumn = 0;
    int CurrentIndex = 0;
    bool TableStarted = false;
};

void BeginLayout(LayoutType type, Vector2 itemSize, Vector2 spacing);
void NextLayoutItem();
void EndLayout();

} // namespace Lumen::LUI