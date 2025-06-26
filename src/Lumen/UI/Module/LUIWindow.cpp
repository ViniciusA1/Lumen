#include "Lumen/UI/Module/LUIWindow.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

bool Begin(const std::string &name, bool *p_open, WindowFlags flags)
{
    return ImGui::Begin(name.c_str(), p_open, static_cast<int>(flags));
}

void End()
{
    ImGui::End();
}

bool BeginChild(const std::string &label, const Vector2 &size, ChildFlags childFlags,
                WindowFlags windowFlags)
{
    return ImGui::BeginChild(label.c_str(), {size.x, size.y},
                             static_cast<int>(childFlags), static_cast<int>(windowFlags));
}

void EndChild()
{
    ImGui::EndChild();
}

void Centralize(CondFlags cond)
{
    Vector2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos({center.x, center.y}, static_cast<int>(cond), {0.5f, 0.5f});
}

Vector2 GetContentRegionAvail()
{
    ImVec2 region = ImGui::GetContentRegionAvail();
    return {region.x, region.y};
}

Vector2 GetViewportCenter()
{
    ImVec2 viewport = ImGui::GetMainViewport()->GetCenter();
    return {viewport.x, viewport.y};
}

Vector2 GetWindowContentRegionMax()
{
    ImVec2 region = ImGui::GetWindowContentRegionMax();
    return {region.x, region.y};
}

float GetWindowHeight()
{
    return ImGui::GetWindowHeight();
}

Vector2 GetWindowPos()
{
    ImVec2 windowPos = ImGui::GetWindowPos();
    return {windowPos.x, windowPos.y};
}

float GetWindowWidth()
{
    return ImGui::GetWindowWidth();
}

void SetNextWindowPos(const Vector2 &pos, CondFlags cond, const Vector2 &pivot)
{
    ImGui::SetNextWindowPos({pos.x, pos.y}, static_cast<int>(cond), {pivot.x, pivot.y});
}

void SetNextWindowSize(const Vector2 &size, CondFlags cond)
{
    ImGui::SetNextWindowSize({size.x, size.y}, static_cast<int>(cond));
}

} // namespace Lumen::LUI