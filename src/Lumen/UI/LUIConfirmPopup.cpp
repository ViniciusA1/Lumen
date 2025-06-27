#include "Lumen/UI/LUIConfirmPopup.hpp"
#include "Lumen/UI/LUI.hpp"
#include "Lumen/UI/Module/LUIFont.hpp"
#include "Lumen/UI/Module/LUIWidget.hpp"

namespace Lumen
{

LUIConfirmPopup::LUIConfirmPopup(std::string label, std::string message, Action onConfirm,
                                 Action onCancel)
    : LUIPopup(std::move(label), {0.0f, 0.0f}, LUI::WindowFlags::NoResize),
      m_Message(std::move(message)), m_OnConfirm(std::move(onConfirm)),
      m_OnCancel(std::move(onCancel))
{
}

std::string LUIConfirmPopup::GetMessage() const
{
    return m_Message;
}

Action LUIConfirmPopup::GetOnCancel() const
{
    return m_OnCancel;
}

Action LUIConfirmPopup::GetOnConfirm() const
{
    return m_OnConfirm;
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
    LUI::Text(m_Message);
    LUI::NewLine();

    Vector2 yesSize = LUI::CalcTextSize("Yes");
    Vector2 noSize = LUI::CalcTextSize("No");
    yesSize.x += LUI::GetStyle().FramePadding.x * 2;
    noSize.x += LUI::GetStyle().FramePadding.x * 2;

    float spacing = LUI::GetStyle().ItemSpacing.y;
    float totalWidth = yesSize.x + noSize.x + spacing;
    float windowWidth = LUI::GetContentRegionAvail().x;
    float cursorX = (windowWidth - totalWidth) * 0.5f;
    LUI::SetCursorPosX(cursorX);

    if (LUI::Button("Yes"))
    {
        m_OnConfirm();
        Close();
    }

    LUI::SameLine();

    if (LUI::Button("No"))
    {
        m_OnCancel();
        Close();
    }
}

} // namespace Lumen
