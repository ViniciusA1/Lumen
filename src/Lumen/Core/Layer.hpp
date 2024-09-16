#pragma once

#include <string>

namespace Lumen
{

class Layer
{
public:
    Layer(std::string name, bool visible = true);
    virtual ~Layer() = default;

    [[nodiscard]] std::string GetName() const { return m_Name; }
    [[nodiscard]] bool IsVisible() const { return m_IsVisible; }
    void SetVisible(bool visible) { m_IsVisible = visible; }

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnEvent() {}
    virtual void OnUpdate() {}
    virtual void OnDraw() {}

private:
    std::string m_Name;
    bool m_IsVisible;
};

} // namespace Lumen