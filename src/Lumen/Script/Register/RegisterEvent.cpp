#include "Lumen/Script/Register/RegisterAPI.hpp"

namespace Lumen
{

static void RegisterEventBus();
static void RegisterFileEvent();
static void RegisterKeyboardEvent();
static void RegisterLayerEvent();
static void RegisterMouseEvent();
static void RegisterNetworkEvent();
static void RegisterPhysics2DEvent();
static void RegisterSceneEvent();
static void RegisterWindowEvent();

void RegisterEventAPI()
{
    RegisterEventBus();
    RegisterFileEvent();
    RegisterKeyboardEvent();
    RegisterLayerEvent();
    RegisterMouseEvent();
    RegisterNetworkEvent();
    RegisterPhysics2DEvent();
    RegisterSceneEvent();
    RegisterWindowEvent();
}

static void RegisterEventBus()
{
}

static void RegisterFileEvent()
{
}

static void RegisterKeyboardEvent()
{
}

static void RegisterLayerEvent()
{
}

static void RegisterMouseEvent()
{
}

static void RegisterNetworkEvent()
{
}

static void RegisterPhysics2DEvent()
{
}

static void RegisterSceneEvent()
{
}

static void RegisterWindowEvent()
{
}

} // namespace Lumen