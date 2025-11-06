#pragma once

#include "Lumen/Network/Address.hpp"
#include "Lumen/Network/Channel.hpp"
#include "Lumen/Network/Packet.hpp"
#include "Lumen/Network/PeerState.hpp"

using ENetPeer = struct _ENetPeer;

namespace Lumen
{

class Peer
{
public:
    Peer() = default;
    Peer(::ENetPeer *peer);

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] Address GetAddress() const;
    [[nodiscard]] uint32_t GetMTU() const;
    [[nodiscard]] uint32_t GetPacketLoss() const;
    [[nodiscard]] uint32_t GetPacketsLost() const;
    [[nodiscard]] uint32_t GetPacketsSent() const;
    [[nodiscard]] uint32_t GetRoundTripTime() const;
    [[nodiscard]] PeerState GetState() const;
    [[nodiscard]] uint32_t GetThrottleInterval() const;
    [[nodiscard]] uint32_t GetThrottleAcceleration() const;
    [[nodiscard]] uint32_t GetThrottleDeceleration() const;
    [[nodiscard]] uint32_t GetTimeoutLimit() const;
    [[nodiscard]] uint32_t GetTimeoutMinimum() const;
    [[nodiscard]] uint32_t GetTimeoutMaximum() const;
    [[nodiscard]] uint64_t GetTotalDataReceived() const;
    [[nodiscard]] uint64_t GetTotalDataSent() const;

    void SetThrottle(uint32_t interval, uint32_t acceleration, uint32_t deceleration);
    void SetTimeouts(uint32_t limit, uint32_t minimum, uint32_t maximum);

    void Disconnect(uint32_t data = 0);
    void DisconnectLater(uint32_t data = 0);
    void DisconnectNow(uint32_t data = 0);
    void Ping();
    void Reset();
    bool Send(Channel channel, const Packet &packet);

    operator ENetPeer *() const;

private:
    ::ENetPeer *m_Peer = nullptr;
};

} // namespace Lumen