#pragma once

#include "Lumen/Application/Application.hpp"
#include "Lumen/Application/EngineModule.hpp"

namespace Lumen
{

class DefaultModule : public EngineModule
{
public:
    DefaultModule(Application &app, ApplicationArgs args = {});

    void Build() override;

protected:
    virtual void InitArgs();
    virtual void InitLogging();
    virtual void InitWindow();
    virtual void InitAssets();
    virtual void InitScript();
    virtual void InitScenes();
    virtual void InitComponents();
    virtual void InitSystems();
    virtual void InitLUI();

protected:
    ApplicationArgs m_ExternalArgs;
};

} // namespace Lumen