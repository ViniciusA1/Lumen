#pragma once

#include "Lumen/Application/Application.hpp"

namespace Lumen
{

class EngineInitializer
{
public:
    EngineInitializer(Application &app);

    virtual void Run();

protected:
    virtual void InitArgs();
    virtual void InitLogging();
    virtual void InitWindow();
    virtual void InitAssets();
    virtual void InitScript();
    virtual void InitScenes();
    virtual void InitComponents();
    virtual void InitSystems();
    virtual void InitPrefabs();
    virtual void InitLayers();

protected:
    Application &m_App;
};

} // namespace Lumen