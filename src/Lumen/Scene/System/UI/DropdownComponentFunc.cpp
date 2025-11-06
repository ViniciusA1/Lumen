#include "Lumen/Scene/System/UI/DropdownComponentFunc.hpp"
#include "Lumen/Input/Input.hpp"
#include "Lumen/Math/Math.hpp"
#include "Lumen/Math/Rectangle.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform,
                     const DropdownComponent &dropdown)
{
}

template <>
void UpdateUIComponent(TransformComponent &transform, DropdownComponent &dropdown)
{
    Vector2 mousePos = Input::GetMousePosition();

    if (Input::IsMouseButtonPressed(MouseCode::ButtonLeft))
    {
        if (Rectangle(transform).Contains(mousePos))
        {
            dropdown.IsExpanded = !dropdown.IsExpanded;
            return;
        }

        if (dropdown.IsExpanded)
        {
            int visibleCount =
                Math::Min(dropdown.MaxVisibleItems, (int)dropdown.Options.size());
            for (int i = 0; i < visibleCount; ++i)
            {
                Vector2 optionPos =
                    Vector2(transform.Position) + Vector2(0, (i + 1) * transform.Scale.y);
                Rectangle optionRect(optionPos, transform.Scale);

                if (optionRect.Contains(mousePos))
                {
                    dropdown.SelectedIndex = i;
                    dropdown.IsExpanded = false;
                    dropdown.OnValueChanged(i, dropdown.Options[i]);
                    break;
                }
            }
        }
    }

    if (dropdown.IsExpanded && Input::IsMouseButtonPressed(MouseCode::ButtonLeft) &&
        !Rectangle(transform).Contains(mousePos))
        dropdown.IsExpanded = false;
}

} // namespace Lumen