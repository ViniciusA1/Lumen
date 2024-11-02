#pragma once

#include <array>

namespace Lumen
{

class ConsolePanel
{
public:
    ConsolePanel() = default;

    void Draw();

private:
    bool m_ScrollToBottom = false;
    std::array<char, 256> m_FilterBuffer = {""};
};

} // namespace Lumen