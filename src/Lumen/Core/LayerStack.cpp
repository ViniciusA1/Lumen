#include "Lumen/Core/LayerStack.hpp"
#include <algorithm>

namespace Lumen
{

LayerStack::~LayerStack()
{
    for (Ref<Layer> &layer : m_Layers)
    {
        layer->OnDetach();
    }
}

void LayerStack::PushLayer(Ref<Layer> layer)
{
    m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
    m_LayerInsertIndex++;
    layer->OnAttach();
}

void LayerStack::PushOverlay(Ref<Layer> overlay)
{
    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
}

void LayerStack::PopLayer(const Ref<Layer> &layer)
{
    auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex,
                        layer);
    if (it != m_Layers.begin() + m_LayerInsertIndex)
    {
        layer->OnDetach();
        m_Layers.erase(it);
        m_LayerInsertIndex--;
    }
}

void LayerStack::PopOverlay(const Ref<Layer> &overlay)
{
    auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(),
                        overlay);
    if (it != m_Layers.end())
    {
        overlay->OnDetach();
        m_Layers.erase(it);
    }
}

} // namespace Lumen