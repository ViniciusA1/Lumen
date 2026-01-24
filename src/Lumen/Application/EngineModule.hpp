#pragma once

#include "Lumen/Application/Application.hpp"

namespace Lumen
{

class EngineModule
{
public:
    EngineModule(Application &app) : m_App(app) {}

    virtual void Build() = 0;

protected:
    Application &m_App;
};

} // namespace Lumen