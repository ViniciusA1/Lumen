#include "Lumen/Network/Network.hpp"

#include "enet.h"

namespace Lumen
{

static bool s_IsInitialized = false;

void Network::Init()
{
    if (s_IsInitialized)
        return;

    if (enet_initialize())
        s_IsInitialized = true;
}

void Network::Shutdown()
{
    if (!s_IsInitialized)
        return;

    enet_deinitialize();
    s_IsInitialized = false;
}

} // namespace Lumen