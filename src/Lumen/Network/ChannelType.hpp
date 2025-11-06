#pragma once

namespace Lumen
{

enum class ChannelType
{
    Reliable = 0,
    Unreliable = 1,
    Sequenced = 2,
    Custom
};

} // namespace Lumen