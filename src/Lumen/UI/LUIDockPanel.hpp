#pragma once

#include "Lumen/UI/LUIStructures.hpp"

#include <string>

namespace Lumen
{

class LUIDockPanel
{
public:
    LUIDockPanel(std::string label, LUI::WindowFlags flags, bool isOpen = true);

    [[nodiscard]] bool IsOpen() const;

    void Close();
    void Open();

    void Draw();
    virtual void OnDraw() = 0;

protected:
    std::string m_Label;
    LUI::WindowFlags m_Flags;
    bool m_IsOpen = true;
};

} // namespace Lumen