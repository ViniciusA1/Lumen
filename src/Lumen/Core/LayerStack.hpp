#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Core/Memory.hpp"
#include <vector>

namespace Lumen
{

class LayerStack
{
public:
    LayerStack() = default;
    ~LayerStack();

    void PushLayer(Ref<Layer> layer);
    void PushOverlay(Ref<Layer> overlay);
    void PopLayer(const Ref<Layer> &layer);
    void PopOverlay(const Ref<Layer> &overlay);

    std::vector<Ref<Layer>>::iterator begin() { return m_Layers.begin(); }
    std::vector<Ref<Layer>>::iterator end() { return m_Layers.end(); }

private:
    std::vector<Ref<Layer>> m_Layers;
    unsigned int m_LayerInsertIndex = 0;
};

} // namespace Lumen