#pragma once

#include "Lumen/Network/Peer.hpp"

namespace Lumen
{

struct NetworkConnectEvent
{
    class Peer Peer;
};

struct NetworkDisconnectEvent
{
    class Peer Peer;
};

struct NetworkReceiveEvent
{
    class Peer Peer;
    uint32_t Type;
    Buffer Data;
    class Channel Channel;
};

struct NetworkSendEvent
{
};

} // namespace Lumen