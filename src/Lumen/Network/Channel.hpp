#pragma once

#include "Lumen/Network/ChannelType.hpp"

#include <cstdint>

namespace Lumen
{

class Channel
{
public:
    Channel() = default;
    Channel(ChannelType type, uint8_t customID = 0);

    [[nodiscard]] uint8_t GetID() const;
    [[nodiscard]] ChannelType GetType() const;

    static Channel Reliable();
    static Channel Unreliable();
    static Channel Sequenced();
    static Channel Custom(uint8_t id);

private:
    ChannelType m_Type = ChannelType::Reliable;
    uint8_t m_ID = 0;
};

} // namespace Lumen