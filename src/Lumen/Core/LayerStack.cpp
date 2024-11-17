#include "Lumen/Core/LayerStack.hpp"

namespace Lumen
{

LayerStack::~LayerStack()
{
    for (const auto &[layerName, layer] : m_LayerMap)
    {
        layer->OnDetach();
    }
}

void LayerStack::PushLayer(const Ref<Layer> &layer)
{
    m_LayerMap[layer->GetName()] = layer;
    layer->OnAttach();
}

void LayerStack::PopLayer(const std::string &name)
{
    m_LayerMap.erase(name);
}

} // namespace Lumen