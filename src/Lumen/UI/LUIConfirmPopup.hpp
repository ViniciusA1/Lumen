#pragma once

#include "Lumen/System/Action.hpp"
#include "Lumen/UI/LUIPopup.hpp"

#include <string>

namespace Lumen
{

class LUIConfirmPopup : public LUIPopup
{
public:
    LUIConfirmPopup(std::string label, std::string message, Action onConfirm,
                    Action onCancel = {});

    [[nodiscard]] std::string GetMessage() const;
    [[nodiscard]] Action GetOnCancel() const;
    [[nodiscard]] Action GetOnConfirm() const;

    void SetMessage(const std::string &message);
    void SetCallbacks(Action onConfirm, Action onCancel = nullptr);

protected:
    void OnDraw() override;

private:
    std::string m_Message;
    Action m_OnConfirm;
    Action m_OnCancel;
};

} // namespace Lumen
