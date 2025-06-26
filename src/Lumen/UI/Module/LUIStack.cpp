#include "Lumen/UI/Module/LUIStack.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

void PushID(int id)
{
    ImGui::PushID(id);
}

void PushID(const std::string &id)
{
    ImGui::PushID(id.c_str());
}

void PopID()
{
    ImGui::PopID();
}

void PushStyleColor(ColorFlags flag, const Color &color)
{
    Vector4 col = color.Normalize();
    ImGui::PushStyleColor(static_cast<int>(flag), {col.x, col.y, col.z, col.w});
}

void PopStyleColor(int count)
{
    ImGui::PopStyleColor(count);
}

void PushStyleVar(StyleFlags flag, float var)
{
    ImGui::PushStyleVar(static_cast<int>(flag), var);
}

void PushStyleVar(StyleFlags flag, const Vector2 &var)
{
    ImGui::PushStyleVar(static_cast<int>(flag), var);
}

void PopStyleVar(int count)
{
    ImGui::PopStyleVar(count);
}

} // namespace Lumen::LUI