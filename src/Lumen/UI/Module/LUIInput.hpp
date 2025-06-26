#pragma once

#include "Lumen/Input/MouseCode.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen::LUI
{

bool IsItemClicked(MouseCode button = MouseCode::ButtonLeft);
bool IsItemHovered();

bool IsMouseDoubleClicked(MouseCode button = MouseCode::ButtonLeft);
bool IsMouseDown(MouseCode button = MouseCode::ButtonLeft);

Vector2 GetCursorPos();
float GetCursorPosX();
float GetCursorPosY();
Vector2 GetCursorScreenPos();

void SetCursorPos(const Vector2 &pos);
void SetCursorPosX(float x);
void SetCursorPosY(float y);
void SetCursorScreenPos(const Vector2 &pos);

} // namespace Lumen::LUI