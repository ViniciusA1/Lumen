#include "Lumen/Event/ApplicationListener.hpp"

namespace Lumen
{

void ApplicationListener::OnWindowResize(WindowResizeEvent &event)
{
    if (m_WindowResizeAction.Func)
    {
        m_WindowResizeAction(event.GetWidth(), event.GetHeight());
    }
}

void ApplicationListener::OnWindowClose(WindowCloseEvent &event)
{
    if (m_WindowCloseAction.Func)
    {
        m_WindowCloseAction(0, 0);
    }
}

void ApplicationListener::BindResizeAction(const ApplicationAction &action)
{
    m_WindowResizeAction = action;
}

void ApplicationListener::BindCloseAction(const ApplicationAction &action)
{
    m_WindowCloseAction = action;
}

void ApplicationListener::UnbindResizeAction()
{
    m_WindowResizeAction = {};
}

void ApplicationListener::UnbindCloseAction()
{
    m_WindowCloseAction = {};
}

} // namespace Lumen