#pragma once

#include "Lumen/Event/KeyboardListener.hpp"
#include "Lumen/Event/MouseListener.hpp"
#include <string>
#include <vector>

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

    std::vector<KeyboardListener> &GetKeyboardListeners() { return m_KeyboardListener; }
    std::vector<MouseListener> &GetMouseListeners() { return m_MouseListener; }
    void AddKeyboardListener(const KeyboardListener &listener);
    void AddMouseListener(const MouseListener &listener);

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnEvent() {}
    virtual void OnUpdate() {}
    virtual void OnDraw() {}

private:
    std::string m_Name;
    bool m_IsVisible;

    std::vector<KeyboardListener> m_KeyboardListener;
    std::vector<MouseListener> m_MouseListener;
};

} // namespace Lumen