#include "Lumen/UI/Style/StyleSerializer.hpp"
#include "nlohmann/json.hpp"
#include <fstream>

namespace Lumen
{

static void DeserializeColor(const nlohmann::json &json, ImGuiStyle &style);
static void DeserializeVar(const nlohmann::json &json, ImGuiStyle &style);
static void SerializeColor(nlohmann::json &json, const ImGuiStyle &style);
static void SerializeVar(nlohmann::json &json, const ImGuiStyle &style);

bool StyleSerializer::Serialize(const Path &path, const Style &style)
{
    std::ofstream file(path.String());
    if (!file.is_open())
    {
        return false;
    }

    nlohmann::json json;

    const ImGuiStyle &imStyle = style.GetImGuiStyle();
    json["Name"] = style.GetName();
    SerializeVar(json, imStyle);
    SerializeColor(json, imStyle);
    file << json.dump(4);

    return true;
}

bool StyleSerializer::Deserialize(const Path &path, Style &style)
{
    std::ifstream file(path.String());
    if (!file.is_open())
    {
        return false;
    }

    nlohmann::json json;
    file >> json;

    ImGuiStyle imStyle = style.GetImGuiStyle();
    DeserializeVar(json, imStyle);
    DeserializeColor(json, imStyle);
    style = {json.value("Name", "Untitled"), imStyle};

    return true;
}

static void DeserializeColor(const nlohmann::json &json, ImGuiStyle &style)
{
    if (json.contains("Colors"))
    {
        for (const auto &[name, field] : Style::ColorMap)
        {
            if (json["Colors"].contains(name))
            {
                const auto &colorArray = json["Colors"][name];
                style.Colors[field] =
                    ImVec4(colorArray[0].get<float>(), colorArray[1].get<float>(),
                           colorArray[2].get<float>(), colorArray[3].get<float>());
            }
        }
    }
}

static ImVec2 DeserializeVec2(const nlohmann::json &json, const std::string &key,
                              const ImVec2 &defaultValue)
{
    auto vec = json.value(key, std::vector<float>{defaultValue.x, defaultValue.y});
    return {vec[0], vec[1]};
}

static void DeserializeVar(const nlohmann::json &json, ImGuiStyle &style)
{
    style.Alpha = json.value("Alpha", style.Alpha);
    style.DisabledAlpha = json.value("DisabledAlpha", style.DisabledAlpha);
    style.WindowPadding = DeserializeVec2(json, "WindowPadding", style.WindowPadding);
    style.WindowRounding = json.value("WindowRounding", style.WindowRounding);
    style.WindowBorderSize = json.value("WindowBorderSize", style.WindowBorderSize);
    style.WindowMinSize = DeserializeVec2(json, "WindowMinSize", style.WindowMinSize);
    style.WindowTitleAlign =
        DeserializeVec2(json, "WindowTitleAlign", style.WindowTitleAlign);
    style.ChildRounding = json.value("ChildRounding", style.ChildRounding);
    style.ChildBorderSize = json.value("ChildBorderSize", style.ChildBorderSize);
    style.PopupRounding = json.value("PopupRounding", style.PopupRounding);
    style.PopupBorderSize = json.value("PopupBorderSize", style.PopupBorderSize);
    style.FramePadding = DeserializeVec2(json, "FramePadding", style.FramePadding);
    style.FrameRounding = json.value("FrameRounding", style.FrameRounding);
    style.FrameBorderSize = json.value("FrameBorderSize", style.FrameBorderSize);
    style.ItemSpacing = DeserializeVec2(json, "ItemSpacing", style.ItemSpacing);
    style.ItemInnerSpacing =
        DeserializeVec2(json, "ItemInnerSpacing", style.ItemInnerSpacing);
    style.IndentSpacing = json.value("IndentSpacing", style.IndentSpacing);
    style.CellPadding = DeserializeVec2(json, "CellPadding", style.CellPadding);
    style.ScrollbarSize = json.value("ScrollbarSize", style.ScrollbarSize);
    style.ScrollbarRounding = json.value("ScrollbarRounding", style.ScrollbarRounding);
    style.GrabMinSize = json.value("GrabMinSize", style.GrabMinSize);
    style.GrabRounding = json.value("GrabRounding", style.GrabRounding);
    style.TabRounding = json.value("TabRounding", style.TabRounding);
    style.TabBorderSize = json.value("TabBorderSize", style.TabBorderSize);
    style.TabBarBorderSize = json.value("TabBarBorderSize", style.TabBarBorderSize);
    style.TabBarOverlineSize = json.value("TabBarOverlineSize", style.TabBarOverlineSize);
    style.TableAngledHeadersAngle =
        json.value("TableAngledHeadersAngle", style.TableAngledHeadersAngle);
    style.TableAngledHeadersTextAlign = DeserializeVec2(
        json, "TableAngledHeadersTextAlign", style.TableAngledHeadersTextAlign);
    style.ButtonTextAlign =
        DeserializeVec2(json, "ButtonTextAlign", style.ButtonTextAlign);
    style.SelectableTextAlign =
        DeserializeVec2(json, "SelectableTextAlign", style.SelectableTextAlign);
    style.SeparatorTextBorderSize =
        json.value("SeparatorTextBorderSize", style.SeparatorTextBorderSize);
    style.SeparatorTextAlign =
        DeserializeVec2(json, "SeparatorTextAlign", style.SeparatorTextAlign);
    style.SeparatorTextPadding =
        DeserializeVec2(json, "SeparatorTextPadding", style.SeparatorTextPadding);
    style.DockingSeparatorSize =
        json.value("DockingSeparatorSize", style.DockingSeparatorSize);
}

static void SerializeColor(nlohmann::json &json, const ImGuiStyle &style)
{
    for (const auto &[name, field] : Style::ColorMap)
    {
        json["Colors"][name] = {style.Colors[field].x, style.Colors[field].y,
                                style.Colors[field].z, style.Colors[field].w};
    }
}

static void SerializeVar(nlohmann::json &json, const ImGuiStyle &style)
{
    json["Alpha"] = style.Alpha;
    json["DisabledAlpha"] = style.DisabledAlpha;
    json["WindowPadding"] = {style.WindowPadding.x, style.WindowPadding.y};
    json["WindowRounding"] = style.WindowRounding;
    json["WindowBorderSize"] = style.WindowBorderSize;
    json["WindowMinSize"] = {style.WindowMinSize.x, style.WindowMinSize.y};
    json["WindowTitleAlign"] = {style.WindowTitleAlign.x, style.WindowTitleAlign.y};
    json["ChildRounding"] = style.ChildRounding;
    json["ChildBorderSize"] = style.ChildBorderSize;
    json["PopupRounding"] = style.PopupRounding;
    json["PopupBorderSize"] = style.PopupBorderSize;
    json["FramePadding"] = {style.FramePadding.x, style.FramePadding.y};
    json["FrameRounding"] = style.FrameRounding;
    json["FrameBorderSize"] = style.FrameBorderSize;
    json["ItemSpacing"] = {style.ItemSpacing.x, style.ItemSpacing.y};
    json["ItemInnerSpacing"] = {style.ItemInnerSpacing.x, style.ItemInnerSpacing.y};
    json["IndentSpacing"] = style.IndentSpacing;
    json["CellPadding"] = {style.CellPadding.x, style.CellPadding.y};
    json["ScrollbarSize"] = style.ScrollbarSize;
    json["ScrollbarRounding"] = style.ScrollbarRounding;
    json["GrabMinSize"] = style.GrabMinSize;
    json["GrabRounding"] = style.GrabRounding;
    json["TabRounding"] = style.TabRounding;
    json["TabBorderSize"] = style.TabBorderSize;
    json["TabBarBorderSize"] = style.TabBarBorderSize;
    json["TabBarOverlineSize"] = style.TabBarOverlineSize;
    json["TableAngledHeadersAngle"] = style.TableAngledHeadersAngle;
    json["TableAngledHeadersTextAlign"] = {style.TableAngledHeadersTextAlign.x,
                                           style.TableAngledHeadersTextAlign.y};
    json["ButtonTextAlign"] = {style.ButtonTextAlign.x, style.ButtonTextAlign.y};
    json["SelectableTextAlign"] = {style.SelectableTextAlign.x,
                                   style.SelectableTextAlign.y};
    json["SeparatorTextBorderSize"] = style.SeparatorTextBorderSize;
    json["SeparatorTextAlign"] = {style.SeparatorTextAlign.x, style.SeparatorTextAlign.y};
    json["SeparatorTextPadding"] = {style.SeparatorTextPadding.x,
                                    style.SeparatorTextPadding.y};
    json["DockingSeparatorSize"] = style.DockingSeparatorSize;
}

} // namespace Lumen