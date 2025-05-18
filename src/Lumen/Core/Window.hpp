#pragma once

#include "Lumen/Core/WindowArgs.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

class Window
{
public:
    Window(WindowArgs args);
    ~Window();

    [[nodiscard]] bool IsCursorHidden() const;
    [[nodiscard]] bool IsCursorOnScreen() const;
    [[nodiscard]] bool IsFocused() const;
    [[nodiscard]] bool IsFullscreen() const;
    [[nodiscard]] bool IsHidden() const;
    [[nodiscard]] bool IsMaximized() const;
    [[nodiscard]] bool IsMinimized() const;
    [[nodiscard]] bool IsReady() const;
    [[nodiscard]] bool IsResized() const;
    [[nodiscard]] bool IsRunning() const;
    [[nodiscard]] bool IsStateEnabled(WindowFlags flag) const;

    [[nodiscard]] Texture2D GetIcon() const;
    [[nodiscard]] std::string GetClipboardText() const;
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] std::string GetTitle() const;

    void SetFocused();
    void SetIcon(const Texture2D &icon);
    void SetMaxSize(int width, int height);
    void SetMinSize(int width, int height);
    void SetOpacity(float opacity);
    void SetPosition(int x, int y);
    void SetSize(int width, int height);
    void SetState(WindowFlags flag);
    void SetTitle(const std::string &title);

    void ClearWindowState(WindowFlags flag);
    void DisableCursor();
    void EnableCursor();
    void HideCursor();
    void MaximizeWindow();
    void MinimizeWindow();
    void RestoreWindow();
    void ShowCursor();
    void ToggleBorderlessWindowed();
    void ToggleFullscreen();

private:
    WindowArgs m_WinData;
};

} // namespace Lumen