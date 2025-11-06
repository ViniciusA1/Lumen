#pragma once

#include "Lumen/Network/Address.hpp"

using ENetHost = struct _ENetHost;

namespace Lumen
{

class Host
{
public:
    Host(const Address &address, size_t maxPeers, size_t channelCount,
         uint32_t incomingBandwidth, uint32_t outgoingBandwidth);
    Host(size_t channelCount);
    ~Host();

    void Flush();
    void PoolEvents(uint32_t timeout = 0);

    operator ::ENetHost *() const;

private:
    ::ENetHost *m_Host = nullptr;
};

} // namespace Lumen