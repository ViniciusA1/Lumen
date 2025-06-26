#include "Lumen/UI/Module/LUILayout.hpp"

#include "imgui.h"
#include <stack>
#include <unordered_map>

namespace Lumen::LUI
{

static void BeginGridLayout(LayoutData &layout);
static void BeginHorizontalLayout(LayoutData &layout);
static void BeginPropertyLayout(LayoutData &layout);
static void BeginVerticalLayout(LayoutData &layout);

static void NextGridLayoutItem(LayoutData &layout);
static void NextHorizontalLayoutItem(LayoutData &layout);
static void NextPropertyLayoutItem(LayoutData &layout);
static void NextVerticalLayoutItem(LayoutData &layout);

static void EndGridLayout(LayoutData &layout);
static void EndHorizontalLayout(LayoutData &layout);
static void EndPropertyLayout(LayoutData &layout);
static void EndVerticalLayout(LayoutData &layout);

static std::stack<LayoutData> s_LayoutStack;

struct LayoutFunctions
{
    void (*Begin)(LayoutData &layout);
    void (*Next)(LayoutData &layout);
    void (*End)(LayoutData &layout);
};

const std::unordered_map<LayoutType, LayoutFunctions> s_LayoutFunctions = {
    {
        LayoutType::Grid,
        {BeginGridLayout, NextGridLayoutItem, EndGridLayout},
    },
    {
        LayoutType::Horizontal,
        {BeginHorizontalLayout, NextHorizontalLayoutItem, EndHorizontalLayout},
    },
    {
        LayoutType::Property,
        {BeginPropertyLayout, NextPropertyLayoutItem, EndPropertyLayout},
    },
    {
        LayoutType::Vertical,
        {BeginVerticalLayout, NextVerticalLayoutItem, EndVerticalLayout},
    },
};

void BeginLayout(LayoutType type, Vector2 itemSize, Vector2 spacing)
{
    LayoutData data = {
        .Type = type,
        .ItemSize = itemSize,
        .Spacing = spacing,
        .Columns = 1,
        .CurrentColumn = 0,
        .TableStarted = true,
    };

    s_LayoutFunctions.at(data.Type).Begin(data);
    s_LayoutStack.push(data);
}

void NextLayoutItem()
{
    auto &data = s_LayoutStack.top();
    s_LayoutFunctions.at(data.Type).Next(data);
}

void EndLayout()
{
    auto &data = s_LayoutStack.top();
    s_LayoutFunctions.at(data.Type).End(data);
    s_LayoutStack.pop();
}

static void BeginGridLayout(LayoutData &layout)
{
    float availableWidth = ImGui::GetContentRegionAvail().x;
    float totalItemWidth = layout.ItemSize.x + layout.Spacing.x;
    layout.Columns =
        totalItemWidth > 0.0f ? std::max(1, (int)(availableWidth / totalItemWidth)) : 1;

    if (ImGui::BeginTable("GridLayout", layout.Columns, ImGuiTableFlags_SizingFixedFit))
    {
        layout.TableStarted = true;
        ImGui::TableNextRow(ImGuiTableRowFlags_None,
                            layout.ItemSize.y + layout.Spacing.y);
        ImGui::TableSetColumnIndex(layout.CurrentColumn);
    }
}

static void BeginHorizontalLayout(LayoutData &layout)
{
    layout.Columns = 9999;

    if (ImGui::BeginTable("HorizontalLayout", layout.Columns,
                          ImGuiTableFlags_SizingFixedFit))
    {
        layout.TableStarted = true;
        ImGui::TableNextRow(ImGuiTableRowFlags_None,
                            layout.ItemSize.y + layout.Spacing.y);
        ImGui::TableSetColumnIndex(layout.CurrentColumn);
    }
}

static void BeginPropertyLayout(LayoutData &layout)
{
    layout.Columns = 2;

    if (ImGui::BeginTable("PropertyGridLayout", layout.Columns,
                          ImGuiTableFlags_SizingStretchProp |
                              ImGuiTableFlags_BordersInnerV))
    {
        layout.TableStarted = true;
        ImGui::TableSetupColumn("##Label", ImGuiTableColumnFlags_WidthFixed, 100.0f);
        ImGui::TableSetupColumn("##Value", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(layout.CurrentColumn);
    }
}

static void BeginVerticalLayout(LayoutData &layout)
{
    layout.Columns = 1;

    if (ImGui::BeginTable("VerticalLayout", layout.Columns,
                          ImGuiTableFlags_SizingFixedFit))
    {
        layout.TableStarted = true;
        ImGui::TableNextRow(ImGuiTableRowFlags_None,
                            layout.ItemSize.y + layout.Spacing.y);
        ImGui::TableSetColumnIndex(layout.CurrentColumn);
    }
}

static void NextGridLayoutItem(LayoutData &layout)
{
    if (!layout.TableStarted)
        return;

    layout.CurrentColumn++;
    layout.CurrentIndex++;

    if (layout.CurrentColumn >= layout.Columns)
    {
        layout.CurrentColumn = 0;
        ImGui::TableNextRow(ImGuiTableRowFlags_None,
                            layout.ItemSize.y + layout.Spacing.y);
    }

    ImGui::TableSetColumnIndex(layout.CurrentColumn);
}

static void NextHorizontalLayoutItem(LayoutData &layout)
{
    if (!layout.TableStarted)
        return;

    layout.CurrentColumn++;
    layout.CurrentIndex++;
    ImGui::TableSetColumnIndex(layout.CurrentColumn);
}

static void NextPropertyLayoutItem(LayoutData &layout)
{
    if (!layout.TableStarted)
        return;

    layout.CurrentColumn++;
    layout.CurrentIndex++;

    if (layout.CurrentColumn >= layout.Columns)
    {
        layout.CurrentColumn = 0;
        ImGui::TableNextRow(ImGuiTableRowFlags_None);
    }

    ImGui::TableSetColumnIndex(layout.CurrentColumn);
}

static void NextVerticalLayoutItem(LayoutData &layout)
{
    if (!layout.TableStarted)
        return;

    layout.CurrentIndex++;

    if (layout.CurrentIndex > 0)
        ImGui::TableNextRow(ImGuiTableRowFlags_None,
                            layout.ItemSize.y + layout.Spacing.y);

    ImGui::TableSetColumnIndex(0);
}

static void EndGridLayout(LayoutData &layout)
{
    if (layout.TableStarted)
        ImGui::EndTable();
}

static void EndHorizontalLayout(LayoutData &layout)
{
    if (layout.TableStarted)
        ImGui::EndTable();
}

static void EndPropertyLayout(LayoutData &layout)
{
    if (layout.TableStarted)
        ImGui::EndTable();
}

static void EndVerticalLayout(LayoutData &layout)
{
    if (layout.TableStarted)
        ImGui::EndTable();
}

} // namespace Lumen::LUI