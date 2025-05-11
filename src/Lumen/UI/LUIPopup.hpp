#pragma once

#include <string>

namespace Lumen
{

class LUIPopup
{
public:
    LUIPopup(std::string label);

    [[nodiscard]] bool IsOpen() const;

    void Close();
    void Open();

    virtual void OnDraw() = 0;

protected:
    std::string m_Label;
    bool m_IsOpen = false;
};

} // namespace Lumen