#include "Lumen/UI/LUIPopup.hpp"
#include "Lumen/UI/LUI.hpp"

namespace Lumen
{

LUIPopup::LUIPopup(std::string label) : m_Label(std::move(label))
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
    LUI::PushOverlay([this]() { OnDraw(); });
}

} // namespace Lumen