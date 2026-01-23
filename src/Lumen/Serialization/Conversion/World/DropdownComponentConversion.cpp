#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const DropdownComponent &dropdown)
{
    Json json, dropdownJson;
    dropdownJson = Serialize(static_cast<const UIComponentBase &>(dropdown));
    dropdownJson << dropdown.Options;
    dropdownJson["SelectedIndex"] << dropdown.SelectedIndex;
    dropdownJson["IsExpanded"] << dropdown.IsExpanded;
    dropdownJson["MaxVisibleItems"] << dropdown.MaxVisibleItems;
    json["Dropdown"] << dropdownJson;
    return json;
}

template <> void Deserialize(const Json &json, DropdownComponent &dropdown)
{
    const Json &dropdownJson = json["Dropdown"];
    Deserialize(dropdownJson, static_cast<UIComponentBase &>(dropdown));
    dropdownJson >> dropdown.Options;
    dropdownJson["SelectedIndex"] >> dropdown.SelectedIndex;
    dropdownJson["IsExpanded"] >> dropdown.IsExpanded;
    dropdownJson["MaxVisibleItems"] >> dropdown.MaxVisibleItems;
}

} // namespace Lumen::JsonSerializer