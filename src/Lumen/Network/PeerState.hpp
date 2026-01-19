#pragma once

namespace Lumen
{

enum class PeerState
{
    Disconnected = 0,
    Connecting = 1,
    AcknowledgingConnect = 2,
    ConnectionPending = 3,
    ConnectionSucceeded = 4,
    Connected = 5,
    DisconnectLater = 6,
    Disconnecting = 7,
    AcknowledgingDisconnect = 8,
    Zombie = 9
};

} // namespace Lumen