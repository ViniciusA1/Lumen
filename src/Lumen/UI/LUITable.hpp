#pragma once

#include "Lumen/UI/LUI.hpp"

#include <functional>
#include <string>
#include <vector>

namespace Lumen
{

template <typename T> class LUITable
{
public:
    using Comparator = std::function<bool(const T &, const T &)>;
    using DrawCellFunc = std::function<void(const T &)>;
    using DrawRowFunc = std::function<void(const T &, int)>;

    struct Column
    {
        std::string Name;
        Comparator Comparator;
        DrawCellFunc DrawCell;
    };

    LUITable(std::string id, LUI::TableFlags flags, std::vector<T> &data)
        : m_ID(std::move(id)), m_Flags(flags), m_Data(data)
    {
    }

    void AddColumn(const Column &column) { m_Columns.push_back(column); }

    void SetDrawRow(DrawRowFunc drawRow) { m_DrawRow = drawRow; }

    void Draw()
    {
        if (!LUI::BeginTable(m_ID.c_str(), m_Columns.size(), m_Flags))
            return;

        for (size_t i = 0; i < m_Columns.size(); ++i)
        {
            LUI::TableSetupColumn(m_Columns[i].Name.c_str(),
                                  i == 0 ? LUI::TableColumnFlags::DefaultSort
                                         : LUI::TableColumnFlags::None);
        }
        LUI::TableHeadersRow();

        LUI::TableSortSpecs sortSpecs = LUI::TableGetSortSpecs();

        if (sortSpecs.IsValid() && sortSpecs.IsDirt() && sortSpecs.GetColumnCount() > 0)
        {
            const auto &spec = sortSpecs.GetColumnSortSpecs(0);
            int columnIndex = spec.GetColumnIndex();

            if (columnIndex >= 0 && columnIndex < m_Columns.size() &&
                m_Columns[columnIndex].Comparator)
            {
                auto comparator = m_Columns[columnIndex].Comparator;
                if (spec.IsAscending())
                    std::sort(m_Data.begin(), m_Data.end(), comparator);
                else
                    std::sort(m_Data.begin(), m_Data.end(),
                              [&](const T &a, const T &b) { return !comparator(a, b); });
            }

            sortSpecs.SetSpecsDirty(false);
        }

        int rowIndex = 0;
        for (const auto &row : m_Data)
        {
            if (m_DrawRow)
            {
                m_DrawRow(row, rowIndex++);
            }
            else
            {
                LUI::TableNextRow();
                for (int col = 0; col < m_Columns.size(); ++col)
                {
                    LUI::TableSetColumnIndex(col);
                    m_Columns[col].DrawCell(row);
                }
            }
        }

        LUI::EndTable();
    }

    [[nodiscard]] const std::vector<T> &GetData() const { return m_Data; }
    [[nodiscard]] std::string GetID() const { return m_ID; }

private:
    bool PassesFilter(const T &row) { return true; }

private:
    std::string m_ID;
    LUI::TableFlags m_Flags;
    std::vector<T> &m_Data;
    std::vector<Column> m_Columns;
    DrawRowFunc m_DrawRow = nullptr;
};

} // namespace Lumen
