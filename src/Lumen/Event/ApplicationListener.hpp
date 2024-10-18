#pragma once

#include "Lumen/Event/Action.hpp"
#include "Lumen/Event/ApplicationEvent.hpp"

namespace Lumen
{

using ApplicationAction = Action<void(int, int)>;

class ApplicationListener
{
public:
    void OnWindowResize(WindowResizeEvent &event);
    void OnWindowClose(WindowCloseEvent &event);

    void BindResizeAction(const ApplicationAction &action);
    void BindCloseAction(const ApplicationAction &action);

    void UnbindResizeAction();
    void UnbindCloseAction();

private:
    ApplicationAction m_WindowResizeAction;
    ApplicationAction m_WindowCloseAction;
};

} // namespace Lumen