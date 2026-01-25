#include "Lumen/UI/Module/LUIWidget.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/UI/LUIIcon.hpp"
#include "Lumen/UI/Module/LUIFont.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

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

void SetNextItemWidth(float width)
{
    ImGui::SetNextItemWidth(width);
}

void SetTooltip(const std::string &text)
{
    ImGui::SetTooltip("%s", text.c_str());
}

bool Button(const std::string &label, const Vector2 &size, bool showBg)
{
    bool pressed = false;

    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));

    if (showBg)
        pressed = ImGui::Button(label.c_str(), {size.x, size.y});
    else
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {0, 0});
        pressed = ImGui::Button(label.c_str(), {size.x, size.y});
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
    }

    ImGui::PopStyleColor();

    return pressed;
}

bool ButtonInvisible(const std::string &label, const Vector2 &size)
{
    return ImGui::InvisibleButton(label.c_str(), size);
}

bool ButtonToggle(const std::string &label, bool &value, const Vector2 &size,
                  const std::string &toggledLabel)
{
    const std::string &displayLabel =
        toggledLabel.empty() ? label : (value ? toggledLabel : label);

    if (value)
        ImGui::PushStyleColor(ImGuiCol_Button,
                              ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive));
    else
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyleColorVec4(ImGuiCol_Button));

    bool pressed = Button(displayLabel.c_str(), size);
    value ^= pressed;

    ImGui::PopStyleColor();
    return pressed;
}

// bool ButtonSwitch(const std::string &label, bool &value)
// {
//     ImGuiWindow *window = ImGui::GetCurrentWindow();
//     if (window->SkipItems)
//         return false;

//     ImGui::PushID(label.c_str());

//     float fontSize = ImGui::GetFontSize();
//     float height = fontSize * 1.0f;
//     float width = height * 1.6f;

//     ImVec2 pos = ImGui::GetCursorScreenPos();
//     ImVec2 size(width, height);
//     ImRect bb(pos, pos + size);

//     ImGuiID id = ImGui::GetID(label.c_str());

//     ImGui::ItemSize(size, ImGui::GetStyle().FramePadding.y);
//     if (!ImGui::ItemAdd(bb, id))
//     {
//         ImGui::PopID();
//         return false;
//     }

//     bool hovered, held;
//     bool clicked = ImGui::ButtonBehavior(bb, id, &hovered, &held);

//     if (clicked)
//         value = !value;

//     static std::unordered_map<ImGuiID, float> animMap;
//     float &t = animMap[id];
//     float target = value ? 1.0f : 0.0f;
//     float speed = 10.0f * ImGui::GetIO().DeltaTime;
//     t = ImClamp(t + (target - t) * speed, 0.0f, 1.0f);

//     ImU32 bgColor = ImColor(
//         ImLerp(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), ImVec4(0.2f, 0.7f, 0.3f, 1.0f), t));
//     ImU32 knobColor = IM_COL32(255, 255, 255, 255);

//     ImDrawList *draw_list = ImGui::GetWindowDrawList();
//     float radius = height * 0.5f - 2.0f;

//     draw_list->AddRectFilled(bb.Min, bb.Max, bgColor, height * 0.5f);

//     float knobX = ImLerp(bb.Min.x + radius + 2.0f, bb.Max.x - radius - 2.0f, t);
//     ImVec2 knobCenter(knobX, bb.Min.y + height * 0.5f);
//     draw_list->AddCircleFilled(knobCenter, radius, knobColor);

//     ImGui::PopID();
//     return clicked;
// }

bool Checkbox(const std::string &label, bool *value)
{
    return ImGui::Checkbox(label.c_str(), value);
}

bool ColorEdit(const std::string &label, Color &color, ColorEditFlags flags)
{
    Vector4 normalized = color.Normalize();
    bool result =
        ImGui::ColorEdit4(label.c_str(), &normalized.x, static_cast<int>(flags));
    color = Color::FromNormalized(normalized);
    return result;
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
    ImGui::DragFloat(("##" + label).c_str(), value, speed, min, max, format.c_str(),
                     static_cast<int>(flags));
}

void DragFloat2(const std::string &label, float *value, float speed, float min, float max,
                const std::string &format, SliderFlags flags)
{
    ImGui::DragFloat2(("##" + label).c_str(), value, speed, min, max, format.c_str(),
                      static_cast<int>(flags));
}

void DragFloat3(const std::string &label, float *value, float speed, float min, float max,
                const std::string &format, SliderFlags flags)
{
    ImGui::DragFloat3(("##" + label).c_str(), value, speed, min, max, format.c_str(),
                      static_cast<int>(flags));
}

void DragVec2(const std::string &label, Vector2 &vec, float speed, float min, float max,
              const Vector2 &reset, const std::string &format, SliderFlags flags)
{
    ImGui::PushID(label.c_str());

    ImGui::Text("%s", label.c_str());
    ImGui::SameLine();

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

    float totalWidth = ImGui::CalcItemWidth();
    float dragWidth = (totalWidth - 4 * ImGui::GetFrameHeight()) / 4.0f;

    auto flag = static_cast<int>(flags);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
    if (ImGui::Button("X", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.x = reset.x;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##X", &vec.x, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
    if (ImGui::Button("Y", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.y = reset.y;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##Y", &vec.y, speed, min, max, format.c_str(), flag);

    ImGui::PopStyleVar();
    ImGui::PopID();
}

void DragVec3(const std::string &label, Vector3 &vec, float speed, float min, float max,
              const Vector3 &reset, const std::string &format, SliderFlags flags)
{
    ImGui::PushID(label.c_str());

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

    float totalWidth = ImGui::GetContentRegionAvail().x;
    float dragWidth = (totalWidth - 3 * ImGui::GetFrameHeight()) / 3.0f;

    auto flag = static_cast<int>(flags);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
    if (ImGui::Button("X", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.x = reset.x;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##X", &vec.x, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
    if (ImGui::Button("Y", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.y = reset.y;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##Y", &vec.y, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
    if (ImGui::Button("Z", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.z = reset.z;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##Z", &vec.z, speed, min, max, format.c_str(), flag);

    ImGui::PopStyleVar();
    ImGui::PopID();
}

void DragVec4(const std::string &label, Vector4 &vec, float speed, float min, float max,
              const Vector4 &reset, const std::string &format, SliderFlags flags)
{
    ImGui::PushID(label.c_str());

    ImGui::Text("%s", label.c_str());
    ImGui::SameLine();

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

    float totalWidth = ImGui::CalcItemWidth();
    float dragWidth = (totalWidth - 4 * ImGui::GetFrameHeight()) / 4.0f;

    auto flag = static_cast<int>(flags);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
    if (ImGui::Button("X", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.x = reset.x;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##X", &vec.x, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
    if (ImGui::Button("Y", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.y = reset.y;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##Y", &vec.y, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
    if (ImGui::Button("Z", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.z = reset.z;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##Z", &vec.z, speed, min, max, format.c_str(), flag);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
    if (ImGui::Button("W", ImVec2{ImGui::GetFrameHeight(), ImGui::GetFrameHeight()}))
        vec.w = reset.w;
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(dragWidth);
    ImGui::DragFloat("##W", &vec.w, speed, min, max, format.c_str(), flag);

    ImGui::PopStyleVar();
    ImGui::PopID();
}

bool Filter(const std::vector<std::string> &filters, int &currentFilter)
{
    return LUI::Combo(ICON_FILTER, filters, currentFilter);
}

bool FilterButton(const std::vector<std::string> &filters, int &currentFilter)
{
    ImVec2 buttonPos = ImGui::GetCursorScreenPos();
    ImVec2 buttonSize = ImGui::CalcTextSize(ICON_FILTER " " ICON_SORT_DOWN);
    buttonSize.x += ImGui::GetStyle().FramePadding.x * 2;

    if (ImGui::Button(ICON_FILTER " " ICON_SORT_DOWN))
    {
        ImGui::OpenPopup("FilterButtonCombo");
    }

    ImVec2 popupPos =
        ImVec2(buttonPos.x + buttonSize.x * 0.5f, buttonPos.y + buttonSize.y + 10);
    ImGui::SetNextWindowPos(popupPos, ImGuiCond_Always, ImVec2(0.5f, 0.0f));

    bool filterChanged = false;
    if (ImGui::BeginPopup("FilterButtonCombo"))
    {
        for (int i = 0; i < filters.size(); i++)
        {
            if (ImGui::Selectable(filters[i].c_str(), currentFilter == i))
            {
                currentFilter = i;
                filterChanged = true;
            }
        }
        ImGui::EndPopup();
    }

    return filterChanged;
}

void Image(const Texture2D &texture, const Vector2 &size, const Vector2 &uv0,
           const Vector2 &uv1, Color tintColor, Color borderColor)
{
    ImGui::Image(texture.GetRendererIDPtr(), {size.x, size.y}, {uv0.x, uv0.y},
                 {uv1.x, uv1.y}, tintColor.Normalize(), borderColor.Normalize());
}

void Image(const Texture2D &texture, float scale, const Vector2 &uv0, const Vector2 &uv1,
           Color tintColor, Color borderColor)
{

    ImGui::Image(texture.GetRendererIDPtr(), texture.GetSize() * scale, {uv0.x, uv0.y},
                 {uv1.x, uv1.y}, tintColor.Normalize(), borderColor.Normalize());
}

bool InputText(const std::string &label, const std::span<char> &buffer, bool expand)
{
    if (expand)
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

    return ImGui::InputText(label.c_str(), buffer.data(), buffer.size());
}

bool InputTextWithHint(const std::string &label, const std::string &hint,
                       const std::span<char> &buffer, bool expand)
{
    if (expand)
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

    return ImGui::InputTextWithHint(label.c_str(), hint.c_str(), buffer.data(),
                                    buffer.size());
}

void ObjectField(const std::string &label, AssetHandle &asset, AssetType type,
                 const Action &onSearch)
{
    ImGui::PushID(label.c_str());
    ImGui::BeginGroup();

    float fieldHeight = ImGui::GetFrameHeight();
    float fieldWidth = ImGui::GetContentRegionAvail().x - fieldHeight;

    std::string typeStr = AssetTypeToString(type);
    auto metadata = AssetManager::GetMetadata(asset);
    std::string displayText = metadata.Path.Filename().IsEmpty()
                                  ? " None (" + typeStr + ")"
                                  : metadata.Path.Filename().String();

    ImVec2 cursorPos = ImGui::GetCursorScreenPos();
    ImVec2 fieldSize = ImVec2(fieldWidth, fieldHeight);
    ImU32 bgColor = ImGui::GetColorU32(ImGuiCol_FrameBg);
    ImU32 borderColor = ImGui::GetColorU32(ImGuiCol_Border);

    ImGui::GetWindowDrawList()->AddRectFilled(
        cursorPos, ImVec2(cursorPos.x + fieldSize.x, cursorPos.y + fieldSize.y), bgColor,
        ImGui::GetStyle().FrameRounding);

    ImGui::GetWindowDrawList()->AddRect(
        cursorPos, ImVec2(cursorPos.x + fieldSize.x, cursorPos.y + fieldSize.y),
        borderColor, ImGui::GetStyle().FrameRounding);

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0, 0});
    ImGui::Selectable(displayText.c_str(), false, ImGuiSelectableFlags_AllowDoubleClick,
                      fieldSize);

    if (ImGui::BeginDragDropTarget())
    {
        if (const ImGuiPayload *payload =
                ImGui::AcceptDragDropPayload(("ASSET_DRAG_" + typeStr).c_str()))
        {
            AssetHandle droppedAsset = *(AssetHandle *)payload->Data;
            asset = droppedAsset;
        }
        ImGui::EndDragDropTarget();
    }

    ImGui::SameLine();
    if (ImGui::Button(ICON_MAGNIFYING_GLASS, {fieldHeight, fieldHeight}))
        onSearch();

    ImGui::PopStyleVar();
    ImGui::EndGroup();
    ImGui::PopID();
}

void SearchBar(const std::span<char> &buffer, bool expand)
{
    if (expand)
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

    ImGui::InputTextWithHint("##Search", ICON_MAGNIFYING_GLASS " Search...",
                             buffer.data(), buffer.size());
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

bool ThumbnailAsset(const Texture2D &texture, const std::string &name,
                    const std::string &description, const Vector2 &size,
                    const Vector4 &uv, bool selected)
{
    ImGui::PushID(name.c_str());

    const float imageHeight = size.y * 0.6f;
    const float textHeight = size.y * 0.4f;
    const float padding = 4.0f;
    bool clicked = false;

    ImVec2 cursorPos = ImGui::GetCursorScreenPos();
    ImVec2 endPos = ImVec2(cursorPos.x + size.x, cursorPos.y + size.y);

    ImU32 bgColor = ImGui::GetColorU32(ImGui::GetStyleColorVec4(ImGuiCol_FrameBg));
    ImGui::GetWindowDrawList()->AddRectFilled(cursorPos, endPos, bgColor, 4.0f, 0);

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0, 0});
    if (ImGui::Selectable("##AssetSelectable", selected, 0, {size.x, size.y}))
        clicked = true;
    ImGui::PopStyleVar();

    ImVec2 imageEnd = ImVec2(cursorPos.x + size.x, cursorPos.y + imageHeight);
    ImGui::GetWindowDrawList()->AddImage(texture.GetRendererIDPtr(), cursorPos, imageEnd,
                                         {uv.x, uv.y}, {uv.z, uv.w});

    ImVec2 textPos = ImVec2(cursorPos.x + padding, cursorPos.y + imageHeight + padding);
    ImGui::SetCursorScreenPos(textPos);
    ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + size.x - 2 * padding);
    ImGui::Text("%s", name.c_str());
    if (!description.empty())
    {
        ImGui::BeginDisabled();
        ImGui::SetCursorScreenPos(ImGui::GetCursorScreenPos() + padding);
        ImGui::Text("%s", description.c_str());
        ImGui::EndDisabled();
    }
    ImGui::PopTextWrapPos();

    ImGui::PopID();
    return clicked;
}

bool ThumbnailAsset(const ThumbnailAssetData &thumbnail, const Vector4 &uv, bool selected)
{
    bool result = ThumbnailAsset(thumbnail.Texture, thumbnail.Name, thumbnail.Description,
                                 thumbnail.Size, uv, selected);
    if (result)
        thumbnail.OnClick();

    return result;
}

bool ThumbnailIcon(const std::string &icon, const std::string &name, const Vector2 &size,
                   bool selected)
{
    ImGui::PushID(name.c_str());
    const float iconHeight = size.y * 0.6f;
    const float textHeight = size.y * 0.4f;
    const float padding = 4.0f;
    bool clicked = false;

    ImVec2 cursorPos = ImGui::GetCursorScreenPos();
    ImVec2 endPos = cursorPos + size;

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0, 0});
    if (ImGui::Selectable("##IconSelectable", selected,
                          ImGuiSelectableFlags_AllowDoubleClick, {size.x, size.y}))
        clicked = true;
    ImGui::PopStyleVar();

    LUI::PushFont(FontScale::x500);
    ImVec2 iconTextSize = ImGui::CalcTextSize(icon.c_str());
    ImVec2 iconPos = ImVec2(cursorPos.x + (size.x - iconTextSize.x) * 0.5f,
                            cursorPos.y + (iconHeight - iconTextSize.y) * 0.5f);
    ImGui::SetCursorScreenPos(iconPos);
    ImGui::TextUnformatted(icon.c_str());
    LUI::PopFont();

    ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + size.x - 2 * padding);
    ImGui::SetCursorScreenPos(ImGui::GetCursorScreenPos() + padding);
    ImGui::Text("%s", name.c_str());
    ImGui::PopTextWrapPos();

    ImGui::PopID();
    return clicked;
}

bool ThumbnailIcon(const ThumbnailIconData &thumbnail, bool selected)
{
    bool result = ThumbnailIcon(thumbnail.Icon, thumbnail.Name, thumbnail.Size, selected);

    if (result)
        thumbnail.OnClick();

    return result;
}

} // namespace Lumen::LUI