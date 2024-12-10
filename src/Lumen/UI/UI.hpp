#pragma once

#include "Lumen/UI/Style/Style.hpp"

namespace Lumen
{

class UI
{
public:
    static void Init();
    static void Shutdown();

    static void Begin();
    static void End();

    static void SetStyle(const Style &style);

private:
    static Style m_Style;
};

} // namespace Lumen