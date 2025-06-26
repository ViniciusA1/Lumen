#include "Lumen/UI/LUIConfirmPopup.hpp"
#include "Lumen/UI/LUI.hpp"

namespace Lumen
{

LUIConfirmPopup::LUIConfirmPopup(std::string label, std::string message, Action onConfirm,
                                 Action onCancel)
    : LUIPopup(std::move(label)), m_Message(std::move(message)),
      m_OnConfirm(std::move(onConfirm)), m_OnCancel(std::move(onCancel))
{
}

void LUIConfirmPopup::SetMessage(const std::string &message)
{
    m_Message = message;
}

void LUIConfirmPopup::SetCallbacks(Action onConfirm, Action onCancel)
{
    m_OnConfirm = std::move(onConfirm);
    m_OnCancel = std::move(onCancel);
}

void LUIConfirmPopup::OnDraw()
{
    LUI::TextWrapped(m_Message);

    constexpr float buttonWidth = 80.0f;
    constexpr float spacing = 20.0f;
    constexpr float totalWidth = (buttonWidth * 2.0f) + spacing;

    const float windowWidth = LUI::GetContentRegionAvail().x;
    const float cursorX = (windowWidth - totalWidth) * 0.5f;

    LUI::SetCursorPosX(cursorX);

    if (LUI::Button("Yes", {buttonWidth, 0}))
    {
        m_OnConfirm();
        Close();
    }

    LUI::SameLine();

    if (LUI::Button("No", {buttonWidth, 0}))
    {
        m_OnCancel();
        Close();
    }
}

} // namespace Lumen
