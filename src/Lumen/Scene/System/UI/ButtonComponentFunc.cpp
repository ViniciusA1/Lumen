#include "Lumen/Scene/System/UI/ButtonComponentFunc.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Input/Input.hpp"

namespace Lumen
{

template <>
void DrawUIComponent(const TransformComponent &transform, const ButtonComponent &button)
{
    Renderer::DrawQuad2D(transform, AssetManager::Get<Texture2D>(button.Texture),
                         button.Colors[static_cast<int>(button.State)]);

    DrawUIComponent<LabelComponent>(transform, button.Label);
}

template <> void UpdateUIComponent(TransformComponent &transform, ButtonComponent &button)
{
    if (button.State == UIComponentState::Disabled)
        return;

    if (!Rectangle(transform).Contains(Input::GetMousePosition()))
    {
        button.State = UIComponentState::Idle;
        return;
    }

    if (Input::IsMouseButtonDown(MouseCode::ButtonLeft))
    {
        button.State = UIComponentState::Pressed;
    }
    else
    {
        if (button.State == UIComponentState::Pressed)
            button.OnClick();

        button.State = UIComponentState::Hovered;
    }
}

} // namespace Lumen