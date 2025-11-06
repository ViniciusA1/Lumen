#pragma once

#include <string>

namespace Lumen
{

class Layer
{
public:
    Layer(std::string name, bool visible = true);
    virtual ~Layer() = default;

    [[nodiscard]] bool IsVisible() const;

    [[nodiscard]] std::string GetName() const;

    void SetVisible(bool visible);

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnDraw() {}

protected:
    std::string m_Name;
    bool m_IsVisible;
};

} // namespace Lumen