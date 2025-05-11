#pragma once

#include "Lumen/Core/InputCode.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/LUIStructures.hpp"
#include "Lumen/UI/LUIStyle.hpp"

#include <functional>
#include <span>
#include <vector>

namespace Lumen::LUI
{

void Init();
void Shutdown();

void BeginUI();
void EndUI();

void SetStyle(const LUIStyle &style);

bool Begin(const std::string &name, bool *p_open = nullptr,
           WindowFlags flags = WindowFlags::None);
void End();

bool BeginChild(const std::string &label, const Vector2 &size = {0, 0},
                ChildFlags childFlags = ChildFlags::None,
                WindowFlags windowFlags = WindowFlags::None);
void EndChild();

void BeginDisabled(bool disabled = true);
void EndDisabled();

void BeginGroup();
void EndGroup();

bool BeginMainMenuBar();
void EndMainMenuBar();

bool BeginMenu(const std::string &label, bool enabled = true);
void EndMenu();

bool BeginPopupContextWindow(const std::string &label = "",
                             PopupFlags flags = PopupFlags::MouseButtonRight);

bool BeginPopupContextItem(const std::string &label = "",
                           PopupFlags flags = PopupFlags::MouseButtonRight);

bool BeginPopupModal(const std::string &name, bool *p_open = nullptr,
                     WindowFlags flags = WindowFlags::None);
void CloseCurrentPopup();
void EndPopup();

bool BeginTable(const std::string &label, int columns,
                TableFlags flags = TableFlags::None,
                const Vector2 &outerSize = {0.0f, 0.0f}, float innerWidth = 0.0f);
void EndTable();

void DockSpaceOverViewport();

void PushID(int id);
void PushID(const std::string &id);
void PopID();

void PushOverlay(const std::function<void()> &overlay);
void PopOverlay();

void PushStyleColor(ColorFlags flag, const Color &color);
void PopStyleColor(int count = 1);

void SetConfigFlags(ConfigFlags flags);

void Centralize(CondFlags cond = CondFlags::None);
void Columns(int count = 1, const char *id = nullptr, bool borders = true);
void NextColumn();
void NewLine();
void SameLine(float offsetX = 0.0f, float spacing = -1.0f);
void Separator();
void Spacing();

Vector2 CalcTextSize(const std::string &text);
bool IsItemClicked(MouseCode button = MouseCode::ButtonLeft);
bool IsItemHovered();
bool IsMouseDoubleClicked(MouseCode button = MouseCode::ButtonLeft);
bool IsMouseDown(MouseCode button = MouseCode::ButtonLeft);
Vector2 GetContentRegionAvail();
Vector2 GetCursorScreenPos();
Vector2 GetViewportCenter();
Vector2 GetWindowContentRegionMax();
float GetWindowHeight();
Vector2 GetWindowPos();
float GetWindowWidth();

void SetCursorPosX(float x);
void SetNextItemWidth(float width);
void SetNextWindowPos(const Vector2 &pos, CondFlags cond = CondFlags::None,
                      const Vector2 &pivot = {0, 0});
void SetNextWindowSize(const Vector2 &size, CondFlags cond = CondFlags::None);
void SetTooltip(const std::string &text);

void DrawRectangle(const Vector2 &pos, const Vector2 &size, Color color);
void DrawText(const std::string &text, const Vector2 &pos, Color color);

bool Button(const std::string &label, const Vector2 &size = Vector2(0, 0));

bool Checkbox(const std::string &label, bool *value);

bool CollapsingHeader(const std::string &label,
                      TreeNodeFlags flags = TreeNodeFlags::None);

bool Combo(const std::string &label, const std::vector<std::string> &items,
           std::string &currentItem);
bool Combo(const std::string &label, const std::vector<std::string> &items,
           int &currentItem);

void DragFloat(const std::string &label, float *value, float speed = 1.0f,
               float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
               SliderFlags flags = SliderFlags::None);
void DragFloat2(const std::string &label, float *value, float speed = 1.0f,
                float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
                SliderFlags flags = SliderFlags::None);
void DragFloat3(const std::string &label, float *value, float speed = 1.0f,
                float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
                SliderFlags flags = SliderFlags::None);

bool Filter(const std::vector<std::string> &filters, int &currentFilter);
bool FilterButton(const std::vector<std::string> &filters, int &currentFilter);

void Image(unsigned int *textureID, const Vector2 &size,
           const Vector2 &uv0 = Vector2(0, 0), const Vector2 &uv1 = Vector2(1, 1),
           Color tintColor = Color::White, Color borderColor = Color(0, 0, 0, 0));

bool InputText(const std::string &label, const std::span<char> &buffer);
bool InputTextWithHint(const std::string &label, const std::string &hint,
                       const std::span<char> &buffer);

bool MenuItem(const std::string &label, const std::string &shortcut = "",
              bool selected = false, bool enabled = true);

void OpenPopup(const std::string &label, PopupFlags flags = PopupFlags::None);

void SearchBar(const std::span<char> &buffer);

bool Selectable(const std::string &label, bool selected = false,
                SelectableFlags flags = SelectableFlags::None,
                const Vector2 &size = {0, 0});

bool SliderFloat(const std::string &label, float *value, float min, float max);

void TableHeadersRow();
void TableNextRow(TableRowFlags flags = TableRowFlags::None, float minHeight = 0.0f);
void TableSetupColumn(const std::string &label,
                      TableColumnFlags flags = TableColumnFlags::None,
                      float initWidth = 0.0f, unsigned int userID = 0);
void TableSetColumnIndex(int column);
void TableSetupScrollFreeze(int cols, int rows);

void Text(const std::string &text);
void TextDisabled(const std::string &text);
void TextWrapped(const std::string &text);

bool TreeNode(const std::string &label, TreeNodeFlags flags = TreeNodeFlags::None);
void TreePop();

} // namespace Lumen::LUI