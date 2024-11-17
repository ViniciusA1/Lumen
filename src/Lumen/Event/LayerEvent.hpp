#pragma once

#include "Lumen/Core/Layer.hpp"
#include "Lumen/Core/Memory.hpp"
#include <string>

namespace Lumen
{

class LayerPushEvent
{
public:
    LayerPushEvent(Ref<Layer> layer);

    [[nodiscard]] Ref<Layer> GetLayer() const;
    [[nodiscard]] std::string ToString() const;

private:
    Ref<Layer> m_Layer;
};

class LayerPopEvent
{
public:
    LayerPopEvent(std::string name);

    [[nodiscard]] std::string GetLayerName() const;
    [[nodiscard]] std::string ToString() const;

private:
    std::string m_LayerName;
};

} // namespace Lumen