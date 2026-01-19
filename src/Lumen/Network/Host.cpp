#include "Lumen/Network/Host.hpp"

#include "enet.h"

namespace Lumen
{

Host::Host(const Address &address, size_t maxPeers, size_t channelCount,
           uint32_t incomingBandwidth, uint32_t outgoingBandwidth)
{
    ENetAddress enetAddr = address;
    m_Host = enet_host_create(&enetAddr, maxPeers, channelCount, incomingBandwidth,
                              outgoingBandwidth);
}

Host::Host(size_t channelCount)
{
    m_Host = enet_host_create(nullptr, 1, channelCount, 0, 0);
}

Host::~Host()
{
    if (m_Host == nullptr)
        return;

    enet_host_destroy(m_Host);
    m_Host = nullptr;
}

Host::operator ::ENetHost *() const
{
    return m_Host;
}

} // namespace Lumen