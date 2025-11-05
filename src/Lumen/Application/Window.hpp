#pragma once

#include "Lumen/Application/WindowArgs.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Vector2.hpp"

namespace Lumen
{

class Window
{
public:
    Window() = default;
    explicit Window(WindowArgs args);

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

    [[nodiscard]] AssetHandle GetIcon() const;
    [[nodiscard]] std::string GetClipboardText() const;
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] std::string GetTitle() const;

    void SetFocused();
    void SetIcon(const Texture2D &icon);
    void SetMaxSize(int width, int height);
    void SetMaxSize(const Vector2 &size);
    void SetMinSize(int width, int height);
    void SetMinSize(const Vector2 &size);
    void SetOpacity(float opacity);
    void SetPosition(int x, int y);
    void SetPosition(const Vector2 &position);
    void SetSize(int width, int height);
    void SetSize(const Vector2 &size);
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
    void Close();

private:
    WindowArgs m_WinData;

    friend class Application;
};

} // namespace Lumen