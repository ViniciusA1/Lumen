#include "Lumen/UI/Module/LUIInput.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

bool IsItemClicked(MouseCode button)
{
    return ImGui::IsItemClicked(static_cast<int>(button));
}

bool IsItemHovered()
{
    return ImGui::IsItemHovered();
}

bool IsMouseDoubleClicked(MouseCode button)
{
    return ImGui::IsMouseDoubleClicked(static_cast<int>(button));
}

bool IsMouseDown(MouseCode button)
{
    return ImGui::IsMouseDown(static_cast<int>(button));
}

Vector2 GetCursorPos()
{
    ImVec2 pos = ImGui::GetCursorPos();
    return {pos.x, pos.y};
}

float GetCursorPosX()
{
    return ImGui::GetCursorPosX();
}

float GetCursorPosY()
{
    return ImGui::GetCursorPosY();
}

Vector2 GetCursorScreenPos()
{
    ImVec2 screenPos = ImGui::GetCursorScreenPos();
    return {screenPos.x, screenPos.y};
}

void SetCursorPos(const Vector2 &pos)
{
    ImGui::SetCursorPos(pos);
}

void SetCursorPosX(float x)
{
    ImGui::SetCursorPosX(x);
}

void SetCursorPosY(float y)
{
    ImGui::SetCursorPosY(y);
}

void SetCursorScreenPos(const Vector2 &pos)
{
    ImGui::SetCursorScreenPos(pos);
}

} // namespace Lumen::LUI