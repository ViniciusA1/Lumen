#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

class TableSortSpecs;

bool BeginTable(const std::string &label, int columns,
                TableFlags flags = TableFlags::None,
                const Vector2 &outerSize = {0.0f, 0.0f}, float innerWidth = 0.0f);
void EndTable();

void Columns(int count = 1, const char *id = nullptr, bool borders = true);
void NextColumn();
void SetColumnWidth(int index, float width);

TableSortSpecs TableGetSortSpecs();

void TableHeadersRow();
void TableNextRow(TableRowFlags flags = TableRowFlags::None, float minHeight = 0.0f);

void TableSetupColumn(const std::string &label,
                      TableColumnFlags flags = TableColumnFlags::None,
                      float initWidth = 0.0f, unsigned int userID = 0);

void TableSetColumnIndex(int column);
void TableSetupScrollFreeze(int cols, int rows);

} // namespace Lumen::LUI

struct ImGuiTableColumnSortSpecs;
struct ImGuiTableSortSpecs;

namespace Lumen::LUI
{

class TableColumnSortSpecs
{
public:
    TableColumnSortSpecs() = default;
    TableColumnSortSpecs(const ImGuiTableColumnSortSpecs *sortSpecs);

    [[nodiscard]] bool IsAscending() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] int GetColumnUserID() const;
    [[nodiscard]] int GetColumnIndex() const;
    [[nodiscard]] int GetSortOrder() const;

    operator const ImGuiTableColumnSortSpecs *() const;

private:
    const ImGuiTableColumnSortSpecs *m_ColumnSortSpecs = nullptr;
};

class TableSortSpecs
{
public:
    TableSortSpecs() = default;
    TableSortSpecs(ImGuiTableSortSpecs *sortSpecs);

    [[nodiscard]] bool IsDirt() const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] int GetColumnCount() const;
    [[nodiscard]] TableColumnSortSpecs GetColumnSortSpecs(int index) const;

    void SetSpecsDirty(bool dirty) const;

    operator ImGuiTableSortSpecs *() const;

private:
    ImGuiTableSortSpecs *m_SortSpecs = nullptr;
};

} // namespace Lumen::LUI