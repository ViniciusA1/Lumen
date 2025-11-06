#include "Lumen/Network/Channel.hpp"

namespace Lumen
{

Channel::Channel(ChannelType type, uint8_t customID) : m_Type(type), m_ID(customID)
{
}

uint8_t Channel::GetID() const
{
    return m_ID;
}

ChannelType Channel::GetType() const
{
    return m_Type;
}

Channel Channel::Reliable()
{
    return {ChannelType::Reliable, 0};
}

Channel Channel::Unreliable()
{
    return {ChannelType::Unreliable, 1};
}

Channel Channel::Sequenced()
{
    return {ChannelType::Sequenced, 2};
}

Channel Channel::Custom(uint8_t id)
{
    return {ChannelType::Custom, id};
}

} // namespace Lumen