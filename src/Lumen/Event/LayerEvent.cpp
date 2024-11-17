#include "Lumen/Event/LayerEvent.hpp"

namespace Lumen
{

LayerPushEvent::LayerPushEvent(Ref<Layer> layer) : m_Layer(std::move(layer))
{
}

Ref<Layer> LayerPushEvent::GetLayer() const
{
    return m_Layer;
}

std::string LayerPushEvent::ToString() const
{
    return "LayerPushEvent: " + m_Layer->GetName();
}

LayerPopEvent::LayerPopEvent(std::string name) : m_LayerName(std::move(name))
{
}

std::string LayerPopEvent::GetLayerName() const
{
    return m_LayerName;
}

std::string LayerPopEvent::ToString() const
{
    return "LayerPopEvent: " + m_LayerName;
}

} // namespace Lumen