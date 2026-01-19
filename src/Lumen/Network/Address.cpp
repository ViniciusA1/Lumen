#include "Lumen/Network/Address.hpp"

#include "enet.h"
#include <array>

namespace Lumen
{

Address::Address() : m_Host("0.0.0.0"), m_Port(0)
{
}

Address::Address(const ::ENetAddress &address)
{
    std::array<char, 255> name;
    enet_address_get_host_ip(&address, name.data(), name.size());
    m_Host = name.data();
    m_Port = address.port;
}

Address::Address(std::string host, uint16_t port) : m_Host(std::move(host)), m_Port(port)
{
}

std::string Address::GetIP() const
{
    return m_Host;
}

uint16_t Address::GetPort() const
{
    return m_Port;
}

std::string Address::ToString() const
{
    return m_Host + ":" + std::to_string(m_Port);
}

void Address::SetHost(const std::string &host)
{
    m_Host = host;
}

void Address::SetPort_(uint16_t port)
{
    m_Port = port;
}

bool Address::operator==(const Address &other) const
{
    return m_Host == other.m_Host && m_Port == other.m_Port;
}

bool Address::operator!=(const Address &other) const
{
    return !(*this == other);
}

Address::operator ::ENetAddress() const
{
    ENetAddress address{};
    address.port = m_Port;
    enet_address_set_host(&address, m_Host.c_str());
    return address;
}

} // namespace Lumen