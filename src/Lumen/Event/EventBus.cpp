#include "Lumen/Event/EventBus.hpp"

namespace Lumen
{

std::unordered_map<std::type_index, std::vector<EventCallbackFunction>>
    EventBus::m_Subscribers;

}