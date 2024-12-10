#pragma once

#include "imgui.h"
#include <map>
#include <string>

namespace Lumen
{

class Style
{
public:
    static const std::map<std::string, ImGuiStyleVar_> VarMap;
    static const std::map<std::string, ImGuiCol_> ColorMap;

public:
    Style() = default;
    Style(std::string name);
    Style(const ImGuiStyle &style);
    Style(std::string name, const ImGuiStyle &style);

    [[nodiscard]] const ImGuiStyle &GetImGuiStyle() const;
    [[nodiscard]] std::string GetName() const;

private:
    std::string m_Name;
    ImGuiStyle m_ImGuiStyle;
};

} // namespace Lumen