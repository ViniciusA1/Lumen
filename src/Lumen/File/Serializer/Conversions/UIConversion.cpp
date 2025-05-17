#include "Lumen/File/Serializer/Conversions/UIConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LUIStyle &style)
{
    Json json;

    json["Name"] << style.Name;
    json["Alpha"] << style.Alpha;
    json["DisabledAlpha"] << style.DisabledAlpha;
    json["WindowPadding"] << style.WindowPadding;
    json["WindowRounding"] << style.WindowRounding;
    json["WindowBorderSize"] << style.WindowBorderSize;
    json["WindowMinSize"] << style.WindowMinSize;
    json["WindowTitleAlign"] << style.WindowTitleAlign;
    json["ChildRounding"] << style.ChildRounding;
    json["ChildBorderSize"] << style.ChildBorderSize;
    json["PopupRounding"] << style.PopupRounding;
    json["PopupBorderSize"] << style.PopupBorderSize;
    json["FramePadding"] << style.FramePadding;
    json["FrameRounding"] << style.FrameRounding;
    json["FrameBorderSize"] << style.FrameBorderSize;
    json["ItemSpacing"] << style.ItemSpacing;
    json["ItemInnerSpacing"] << style.ItemInnerSpacing;
    json["IndentSpacing"] << style.IndentSpacing;
    json["CellPadding"] << style.CellPadding;
    json["ScrollbarSize"] << style.ScrollbarSize;
    json["ScrollbarRounding"] << style.ScrollbarRounding;
    json["GrabMinSize"] << style.GrabMinSize;
    json["GrabRounding"] << style.GrabRounding;
    json["TabRounding"] << style.TabRounding;
    json["TabBorderSize"] << style.TabBorderSize;
    json["TabBarBorderSize"] << style.TabBarBorderSize;
    json["TabBarOverlineSize"] << style.TabBarOverlineSize;
    json["TableAngledHeadersAngle"] << style.TableAngledHeadersAngle;
    json["TableAngledHeadersTextAlign"] << style.TableAngledHeadersTextAlign;
    json["ButtonTextAlign"] << style.ButtonTextAlign;
    json["SelectableTextAlign"] << style.SelectableTextAlign;
    json["SeparatorTextBorderSize"] << style.SeparatorTextBorderSize;
    json["SeparatorTextAlign"] << style.SeparatorTextAlign;
    json["SeparatorTextPadding"] << style.SeparatorTextPadding;
    json["DockingSeparatorSize"] << style.DockingSeparatorSize;

    for (const auto &[name, field] : LUIStyle::ColorMap)
    {
        const auto &color = style.Colors[static_cast<int>(field)];
        json["Colors"][name] << color.ToHex();
    }

    return json;
}

template <> void Deserialize(const Json &json, LUIStyle &style)
{
    json["Name"] >> style.Name;
    json["Alpha"] >> style.Alpha;
    json["DisabledAlpha"] >> style.DisabledAlpha;
    json["WindowPadding"] >> style.WindowPadding;
    json["WindowRounding"] >> style.WindowRounding;
    json["WindowBorderSize"] >> style.WindowBorderSize;
    json["WindowMinSize"] >> style.WindowMinSize;
    json["WindowTitleAlign"] >> style.WindowTitleAlign;
    json["ChildRounding"] >> style.ChildRounding;
    json["ChildBorderSize"] >> style.ChildBorderSize;
    json["PopupRounding"] >> style.PopupRounding;
    json["PopupBorderSize"] >> style.PopupBorderSize;
    json["FramePadding"] >> style.FramePadding;
    json["FrameRounding"] >> style.FrameRounding;
    json["FrameBorderSize"] >> style.FrameBorderSize;
    json["ItemSpacing"] >> style.ItemSpacing;
    json["ItemInnerSpacing"] >> style.ItemInnerSpacing;
    json["IndentSpacing"] >> style.IndentSpacing;
    json["CellPadding"] >> style.CellPadding;
    json["ScrollbarSize"] >> style.ScrollbarSize;
    json["ScrollbarRounding"] >> style.ScrollbarRounding;
    json["GrabMinSize"] >> style.GrabMinSize;
    json["GrabRounding"] >> style.GrabRounding;
    json["TabRounding"] >> style.TabRounding;
    json["TabBorderSize"] >> style.TabBorderSize;
    json["TabBarBorderSize"] >> style.TabBarBorderSize;
    json["TabBarOverlineSize"] >> style.TabBarOverlineSize;
    json["TableAngledHeadersAngle"] >> style.TableAngledHeadersAngle;
    json["TableAngledHeadersTextAlign"] >> style.TableAngledHeadersTextAlign;
    json["ButtonTextAlign"] >> style.ButtonTextAlign;
    json["SelectableTextAlign"] >> style.SelectableTextAlign;
    json["SeparatorTextBorderSize"] >> style.SeparatorTextBorderSize;
    json["SeparatorTextAlign"] >> style.SeparatorTextAlign;
    json["SeparatorTextPadding"] >> style.SeparatorTextPadding;
    json["DockingSeparatorSize"] >> style.DockingSeparatorSize;

    for (const auto &[name, field] : LUIStyle::ColorMap)
    {
        if (!json["Colors"].Contains(name))
            continue;

        if (json["Colors"][name].IsString())
        {
            const auto &hex = json["Colors"][name].Get<std::string>();
            style.Colors[static_cast<int>(field)] = Color::FromHex(hex);
        }
        else
        {
            const auto &colorArray = json["Colors"][name];
            style.Colors[static_cast<int>(field)] = {
                static_cast<unsigned char>(colorArray[0].Get<float>() * 255),
                static_cast<unsigned char>(colorArray[1].Get<float>() * 255),
                static_cast<unsigned char>(colorArray[2].Get<float>() * 255),
                static_cast<unsigned char>(colorArray[3].Get<float>() * 255)};
        }
    }
}

} // namespace Lumen::JsonSerializer
namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const LUIStyle &style)
{
    Yaml yaml;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, LUIStyle &style)
{
}

} // namespace Lumen::YamlSerializer