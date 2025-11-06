#include "Lumen/Network/Peer.hpp"

#include "enet.h"

namespace Lumen
{

Peer::Peer(::ENetPeer *peer) : m_Peer(peer)
{
}

bool Peer::IsValid() const
{
    return m_Peer != nullptr;
}

Address Peer::GetAddress() const
{
    return m_Peer->address;
}

uint32_t Peer::GetMTU() const
{
    return m_Peer->mtu;
}

uint32_t Peer::GetPacketLoss() const
{
    return m_Peer->packetLoss;
}

uint32_t Peer::GetPacketsLost() const
{
    return m_Peer->packetsLost;
}

uint32_t Peer::GetPacketsSent() const
{
    return m_Peer->packetsSent;
}

uint32_t Peer::GetRoundTripTime() const
{
    return m_Peer->roundTripTime;
}

PeerState Peer::GetState() const
{
    return static_cast<PeerState>(m_Peer->state);
}

uint32_t Peer::GetThrottleInterval() const
{
    return m_Peer->packetThrottleInterval;
}

uint32_t Peer::GetThrottleAcceleration() const
{
    return m_Peer->packetThrottleAcceleration;
}

uint32_t Peer::GetThrottleDeceleration() const
{
    return m_Peer->packetThrottleDeceleration;
}

uint32_t Peer::GetTimeoutLimit() const
{
    return m_Peer->timeoutLimit;
}

uint32_t Peer::GetTimeoutMinimum() const
{
    return m_Peer->timeoutMinimum;
}

uint32_t Peer::GetTimeoutMaximum() const
{
    return m_Peer->timeoutMaximum;
}

uint64_t Peer::GetTotalDataReceived() const
{
    return m_Peer->totalDataReceived;
}

uint64_t Peer::GetTotalDataSent() const
{
    return m_Peer->totalDataSent;
}

void Peer::SetThrottle(uint32_t interval, uint32_t acceleration, uint32_t deceleration)
{
    enet_peer_throttle_configure(m_Peer, interval, acceleration, deceleration);
}

void Peer::SetTimeouts(uint32_t limit, uint32_t minimum, uint32_t maximum)
{
    enet_peer_timeout(m_Peer, limit, minimum, maximum);
}

void Peer::Disconnect(uint32_t data)
{
    enet_peer_disconnect(m_Peer, data);
}

void Peer::DisconnectLater(uint32_t data)
{
    enet_peer_disconnect_later(m_Peer, data);
}

void Peer::DisconnectNow(uint32_t data)
{
    enet_peer_disconnect_now(m_Peer, data);
}

void Peer::Ping()
{
    enet_peer_ping(m_Peer);
}

void Peer::Reset()
{
    enet_peer_reset(m_Peer);
}

bool Peer::Send(Channel channel, const Packet &packet)
{
    return enet_peer_send(m_Peer, channel.GetID(), packet) == 0;
}

Peer::operator ENetPeer *() const
{
    return m_Peer;
}

} // namespace Lumen