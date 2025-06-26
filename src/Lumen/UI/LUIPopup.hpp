#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen
{

class LUIPopup
{
public:
    LUIPopup(std::string label, const Vector2 &size = {0.0f, 0.0f},
             LUI::WindowFlags flags = LUI::WindowFlags::None);

    [[nodiscard]] bool IsOpen() const;

    void Close();
    void Open();

    virtual void Draw();
    virtual void OnDraw() = 0;

protected:
    std::string m_Label;
    LUI::WindowFlags m_Flags;
    Vector2 m_Size;
    bool m_IsOpen = false;
};

} // namespace Lumen