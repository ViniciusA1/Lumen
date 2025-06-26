#include "Lumen/UI/LUIPopup.hpp"
#include "Lumen/UI/LUI.hpp"

namespace Lumen
{

LUIPopup::LUIPopup(std::string label, const Vector2 &size, LUI::WindowFlags flags)
    : m_Label(std::move(label)), m_Flags(flags), m_Size(size)
{
}

bool LUIPopup::IsOpen() const
{
    return m_IsOpen;
}

void LUIPopup::Close()
{
    if (!m_IsOpen)
        return;

    m_IsOpen = false;
    LUI::CloseCurrentPopup();
    LUI::PopOverlay();
}

void LUIPopup::Open()
{
    if (m_IsOpen)
        return;

    m_IsOpen = true;
    LUI::PushOverlay([this]() { Draw(); });
}

void LUIPopup::Draw()
{
    LUI::Centralize(LUI::CondFlags::Appearing);
    LUI::SetNextWindowSize(m_Size, LUI::CondFlags::Once);

    LUI::OpenPopup(m_Label);

    if (LUI::BeginPopupModal(m_Label, &m_IsOpen, m_Flags))
    {
        OnDraw();
        LUI::EndPopup();
        if (!m_IsOpen)
            return;
    }

    if (!m_IsOpen)
    {
        LUI::CloseCurrentPopup();
        LUI::PopOverlay();
    }
}

} // namespace Lumen