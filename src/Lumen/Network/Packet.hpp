#pragma once

#include "Lumen/Memory/Buffer.hpp"
#include "Lumen/Network/PacketFlags.hpp"

using ENetPacket = struct _ENetPacket;

namespace Lumen
{

class Packet
{
public:
    Packet() = default;
    Packet(ENetPacket *packet);
    Packet(const void *data, size_t size, PacketFlags flags = PacketFlags::Reliable);
    Packet(const Buffer &buffer, PacketFlags flags = PacketFlags::Reliable);
    Packet(Packet &&other) noexcept;
    Packet &operator=(Packet &&other) noexcept;
    Packet(const Packet &) = delete;
    Packet &operator=(const Packet &) = delete;
    ~Packet();

    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] uint8_t *GetData() const;
    [[nodiscard]] PacketFlags GetFlags() const;
    [[nodiscard]] size_t GetSize() const;

    operator ENetPacket *() const;

private:
    void Destroy();

private:
    ::ENetPacket *m_Packet = nullptr;
};

} // namespace Lumen