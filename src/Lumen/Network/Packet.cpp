#include "Lumen/Network/Packet.hpp"

#include "enet.h"

namespace Lumen
{

Packet::Packet(ENetPacket *packet) : m_Packet(packet)
{
}

Packet::Packet(const void *data, size_t size, PacketFlags flags)
{
    m_Packet = enet_packet_create(data, size, static_cast<uint32_t>(flags));
}

Packet::Packet(const Buffer &buffer, PacketFlags flags)
{
    m_Packet = enet_packet_create(buffer.GetData(), buffer.GetSize(),
                                  static_cast<uint32_t>(flags));
}

Packet::Packet(Packet &&other) noexcept : m_Packet(other.m_Packet)
{
    other.m_Packet = nullptr;
}

Packet &Packet::operator=(Packet &&other) noexcept
{
    if (this != &other)
    {
        Destroy();
        m_Packet = other.m_Packet;
        other.m_Packet = nullptr;
    }

    return *this;
}

Packet::~Packet()
{
    Destroy();
}

bool Packet::IsValid() const
{
    return m_Packet != nullptr;
}

uint8_t *Packet::GetData() const
{
    return IsValid() ? m_Packet->data : nullptr;
}

PacketFlags Packet::GetFlags() const
{
    return IsValid() ? static_cast<PacketFlags>(m_Packet->flags) : PacketFlags::Reliable;
}

size_t Packet::GetSize() const
{
    return IsValid() ? m_Packet->dataLength : 0;
}

void Packet::Destroy()
{
    if (m_Packet)
    {
        enet_packet_destroy(m_Packet);
        m_Packet = nullptr;
    }
}

Packet::operator ENetPacket *() const
{
    return m_Packet;
}

} // namespace Lumen