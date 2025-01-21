#include "Lumen/UI/UI.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/UI/Style/StyleSerializer.hpp"
#include "Lumen/UI/UIStructures.hpp"

#include "imgui.h"

#include "ImGuizmo.h"
#include "rlImGui.h"

namespace Lumen::UI
{

static Lumen::Style s_Style;

void Init()
{
    rlImGuiSetup(true);
    Lumen::StyleSerializer serializer;
    if (serializer.Deserialize({"assets/UI/Style/Dark.json"}, s_Style))
    {
        SetStyle(s_Style);
    }
}

void Shutdown()
{
    rlImGuiShutdown();
}

void BeginUI()
{
    rlImGuiBegin();
    ImGuizmo::BeginFrame();
    Lumen::Renderer::BeginTextureMode();
}

void EndUI()
{
    Lumen::Renderer::EndTextureMode();
    rlImGuiEnd();
}

void SetStyle(const Style &style)
{
    s_Style = style;
    ImGui::GetStyle() = style;
}

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

void BeginDisabled(bool disabled)
{
    ImGui::BeginDisabled(disabled);
}

void EndDisabled()
{
    ImGui::EndDisabled();
}

void BeginGroup()
{
    ImGui::BeginGroup();
}

void EndGroup()
{
    ImGui::EndGroup();
}

bool BeginMainMenuBar()
{
    return ImGui::BeginMainMenuBar();
}

void EndMainMenuBar()
{
    ImGui::EndMainMenuBar();
}

bool BeginMenu(const std::string &label, bool enabled)
{
    return ImGui::BeginMenu(label.c_str(), enabled);
}

void EndMenu()
{
    ImGui::EndMenu();
}

bool BeginPopupContextWindow(const std::string &label, PopupFlags flags)
{
    return ImGui::BeginPopupContextWindow(label.empty() ? nullptr : label.c_str(),
                                          static_cast<int>(flags));
}

bool BeginPopupContextItem(const std::string &label, PopupFlags flags)
{
    return ImGui::BeginPopupContextItem(label.empty() ? nullptr : label.c_str(),
                                        static_cast<int>(flags));
}

bool BeginPopupModal(const std::string &name, bool *p_open, WindowFlags flags)
{
    return ImGui::BeginPopupModal(name.c_str(), p_open, static_cast<int>(flags));
}

void CloseCurrentPopup()
{
    ImGui::CloseCurrentPopup();
}

void EndPopup()
{
    ImGui::EndPopup();
}

bool BeginTable(const std::string &label, int columns, TableFlags flags,
                const Vector2 &outerSize, float innerWidth)
{
    return ImGui::BeginTable(label.c_str(), columns, static_cast<int>(flags),
                             {outerSize.x, outerSize.y}, innerWidth);
}

void EndTable()
{
    ImGui::EndTable();
}

void DockSpaceOverViewport()
{
    ImGui::DockSpaceOverViewport();
}

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

void SetConfigFlags(ConfigFlags flags)
{
    ImGui::GetIO().ConfigFlags |= static_cast<int>(flags);
}

void Columns(int count, const char *id, bool borders)
{
    ImGui::Columns(count, id, borders);
}

void NextColumn()
{
    ImGui::NextColumn();
}

void NewLine()
{
    ImGui::NewLine();
}

void SameLine(float offsetX, float spacing)
{
    ImGui::SameLine(offsetX, spacing);
}

void Separator()
{
    ImGui::Separator();
}

void Spacing()
{
    ImGui::Spacing();
}

Vector2 CalcTextSize(const std::string &text)
{
    ImVec2 size = ImGui::CalcTextSize(text.c_str());
    return {size.x, size.y};
}

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

Vector2 GetContentRegionAvail()
{
    ImVec2 region = ImGui::GetContentRegionAvail();
    return {region.x, region.y};
}

Vector2 GetCursorScreenPos()
{
    ImVec2 screenPos = ImGui::GetCursorScreenPos();
    return {screenPos.x, screenPos.y};
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

void SetCursorPosX(float x)
{
    ImGui::SetCursorPosX(x);
}

void SetNextItemWidth(float width)
{
    ImGui::SetNextItemWidth(width);
}

void SetNextWindowPos(const Vector2 &pos, CondFlags cond, const Vector2 &pivot)
{
    ImGui::SetNextWindowPos({pos.x, pos.y}, static_cast<int>(cond), {pivot.x, pivot.y});
}

void SetNextWindowSize(const Vector2 &size, CondFlags cond)
{
    ImGui::SetNextWindowSize({size.x, size.y}, static_cast<int>(cond));
}

void DrawRectangle(const Vector2 &pos, const Vector2 &size, Color color)
{
    ImGui::GetWindowDrawList()->AddRectFilled(
        {pos.x, pos.y}, {size.x, size.y}, IM_COL32(color.r, color.g, color.b, color.a));
}

void DrawText(const std::string &text, const Vector2 &pos, Color color)
{
    ImGui::GetWindowDrawList()->AddText(
        {pos.x, pos.y}, IM_COL32(color.r, color.g, color.b, color.a), text.c_str());
}

bool Button(const std::string &label, const Vector2 &size)
{
    return ImGui::Button(label.c_str(), {size.x, size.y});
}

bool Checkbox(const std::string &label, bool *value)
{
    return ImGui::Checkbox(label.c_str(), value);
}

bool CollapsingHeader(const std::string &label, TreeNodeFlags flags)
{
    return ImGui::CollapsingHeader(label.c_str(), static_cast<int>(flags));
}

bool Combo(const std::string &label, const std::vector<std::string> &items,
           std::string &currentItem)
{
    bool selectionChanged = false;

    if (ImGui::BeginCombo(label.c_str(), currentItem.c_str()))
    {
        for (const auto &item : items)
        {
            bool isSelected = (currentItem == item);

            if (ImGui::Selectable(item.c_str(), isSelected))
            {
                currentItem = item;
                selectionChanged = true;
            }

            if (isSelected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    return selectionChanged;
}

bool Combo(const std::string &label, const std::vector<std::string> &items,
           int &currentItem)
{
    bool selectionChanged = false;

    if (ImGui::BeginCombo(label.c_str(), items[currentItem].c_str()))
    {
        for (int i = 0; i < items.size(); i++)
        {
            bool isSelected = (currentItem == i);

            if (ImGui::Selectable(items[i].c_str(), isSelected))
            {
                currentItem = i;
                selectionChanged = true;
            }

            if (isSelected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    return selectionChanged;
}

void DragFloat(const std::string &label, float *value, float speed, float min, float max,
               const std::string &format, SliderFlags flags)
{
    ImGui::DragFloat(label.c_str(), value, speed, min, max, format.c_str(),
                     static_cast<int>(flags));
}

void DragFloat2(const std::string &label, float *value, float speed, float min, float max,
                const std::string &format, SliderFlags flags)
{
    ImGui::DragFloat2(label.c_str(), value, speed, min, max, format.c_str(),
                      static_cast<int>(flags));
}

void DragFloat3(const std::string &label, float *value, float speed, float min, float max,
                const std::string &format, SliderFlags flags)
{
    ImGui::DragFloat3(label.c_str(), value, speed, min, max, format.c_str(),
                      static_cast<int>(flags));
}

void Image(unsigned int *textureID, const Vector2 &size, const Vector2 &uv0,
           const Vector2 &uv1)
{
    ImGui::Image(textureID, {size.x, size.y}, {uv0.x, uv0.y}, {uv1.x, uv1.y});
}

bool InputText(const std::string &label, char *buffer, size_t bufferSize)
{
    return ImGui::InputText(label.c_str(), buffer, bufferSize);
}

bool InputTextWithHint(const std::string &label, const std::string &hint, char *buffer,
                       size_t bufferSize)
{
    return ImGui::InputTextWithHint(label.c_str(), hint.c_str(), buffer, bufferSize);
}

bool MenuItem(const std::string &label, const std::string &shortcut, bool selected,
              bool enabled)
{
    return ImGui::MenuItem(label.c_str(), shortcut.empty() ? nullptr : shortcut.c_str(),
                           selected, enabled);
}

void OpenPopup(const std::string &label, PopupFlags flags)
{
    ImGui::OpenPopup(label.c_str(), static_cast<int>(flags));
}

void SearchBar(char *buffer, size_t size)
{
    ImGui::InputTextWithHint("##Search", ICON_FA_MAGNIFYING_GLASS " Search...", buffer,
                             size);
}

bool Selectable(const std::string &label, bool selected, SelectableFlags flags,
                const Vector2 &size)
{
    return ImGui::Selectable(label.c_str(), selected, static_cast<int>(flags),
                             {size.x, size.y});
}

bool SliderFloat(const std::string &label, float *value, float min, float max)
{
    return ImGui::SliderFloat(label.c_str(), value, min, max);
}

void TableHeadersRow()
{
    ImGui::TableHeadersRow();
}

void TableNextRow(TableRowFlags flags, float minHeight)
{
    ImGui::TableNextRow(static_cast<int>(flags), minHeight);
}

void TableSetupColumn(const std::string &label, TableColumnFlags flags, float initWidth,
                      unsigned int userID)
{
    ImGui::TableSetupColumn(label.c_str(), static_cast<int>(flags), initWidth, userID);
}

void TableSetColumnIndex(int column)
{
    ImGui::TableSetColumnIndex(column);
}

void TableSetupScrollFreeze(int cols, int rows)
{
    ImGui::TableSetupScrollFreeze(cols, rows);
}

void Text(const std::string &text)
{
    ImGui::Text("%s", text.c_str());
}

void TextDisabled(const std::string &text)
{
    ImGui::TextDisabled("%s", text.c_str());
}

void TextWrapped(const std::string &text)
{
    ImGui::TextWrapped("%s", text.c_str());
}

bool TreeNode(const std::string &label, TreeNodeFlags flags)
{
    return ImGui::TreeNodeEx(label.c_str(), static_cast<int>(flags));
}

void TreePop()
{
    ImGui::TreePop();
}

} // namespace Lumen::UI