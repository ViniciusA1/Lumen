#include "Lumen/UI/Module/LUITable.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

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

void Columns(int count, const char *id, bool borders)
{
    ImGui::Columns(count, id, borders);
}

void NextColumn()
{
    ImGui::NextColumn();
}

void SetColumnWidth(int index, float width)
{
    ImGui::SetColumnWidth(index, width);
}

TableSortSpecs TableGetSortSpecs()
{
    return ImGui::TableGetSortSpecs();
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

} // namespace Lumen::LUI

namespace Lumen::LUI
{

TableColumnSortSpecs::TableColumnSortSpecs(const ImGuiTableColumnSortSpecs *sortSpecs)
    : m_ColumnSortSpecs(sortSpecs)
{
}

bool TableColumnSortSpecs::IsAscending() const
{
    return m_ColumnSortSpecs &&
           m_ColumnSortSpecs->SortDirection == ImGuiSortDirection_Ascending;
}

bool TableColumnSortSpecs::IsValid() const
{
    return m_ColumnSortSpecs != nullptr;
}

int TableColumnSortSpecs::GetColumnUserID() const
{
    return m_ColumnSortSpecs ? m_ColumnSortSpecs->ColumnUserID : -1;
}

int TableColumnSortSpecs::GetColumnIndex() const
{
    return m_ColumnSortSpecs ? m_ColumnSortSpecs->ColumnIndex : -1;
}

int TableColumnSortSpecs::GetSortOrder() const
{
    return m_ColumnSortSpecs ? m_ColumnSortSpecs->SortOrder : -1;
}

TableColumnSortSpecs::operator const ImGuiTableColumnSortSpecs *() const
{
    return m_ColumnSortSpecs;
}

TableSortSpecs::TableSortSpecs(ImGuiTableSortSpecs *sortSpecs) : m_SortSpecs(sortSpecs)
{
}

bool TableSortSpecs::IsDirt() const
{
    return m_SortSpecs && m_SortSpecs->SpecsDirty;
}

bool TableSortSpecs::IsValid() const
{
    return m_SortSpecs != nullptr;
}

int TableSortSpecs::GetColumnCount() const
{
    return m_SortSpecs ? m_SortSpecs->SpecsCount : 0;
}

TableColumnSortSpecs TableSortSpecs::GetColumnSortSpecs(int index) const
{
    if (!m_SortSpecs || index < 0 || index >= m_SortSpecs->SpecsCount)
        return {};

    return &m_SortSpecs->Specs[index];
}

void TableSortSpecs::SetSpecsDirty(bool dirty) const
{
    if (m_SortSpecs)
        m_SortSpecs->SpecsDirty = dirty;
}

TableSortSpecs::operator ImGuiTableSortSpecs *() const
{
    return m_SortSpecs;
}

} // namespace Lumen::LUI