#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Core/Memory.hpp"
#include <unordered_map>

namespace Lumen
{

class LayerStack
{
public:
    LayerStack() = default;
    ~LayerStack();

    void PushLayer(const Ref<Layer> &layer);
    void PopLayer(const std::string &name);

    auto begin() { return m_LayerMap.begin(); }
    auto end() { return m_LayerMap.end(); }

private:
    std::unordered_map<std::string, Ref<Layer>> m_LayerMap;
};

} // namespace Lumen