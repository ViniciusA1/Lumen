#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Vector2.hpp"
#include <string>

namespace Lumen
{

enum class WindowFlag
{
    VSyncHint = 0x00000040,
    FullScreenMode = 0x00000002,
    Resizable = 0x00000004,
    Undecorated = 0x00000008,
    Hidden = 0x00000080,
    Minimized = 0x00000200,
    Maximized = 0x00000400,
    Unfocused = 0x00000800,
    TopMost = 0x00001000,
    AlwaysRun = 0x00000100,
    Transparent = 0x00000010,
    HighDPI = 0x00002000,
    MousePassThrough = 0x00004000,
    BorderlessWindowedMode = 0x00008000,
    MSAA4xHint = 0x00000020,
    InterlacedHint = 0x00010000
};

struct WindowArgs
{
    std::string Title;
    int Width;
    int Height;
    Ref<Texture2D> Icon;

    WindowArgs(std::string title, int width, int height)
        : Title(std::move(title)), Width(width), Height(height)
    {
    }
};

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
    [[nodiscard]] bool IsStateEnabled(WindowFlag flag) const;

    [[nodiscard]] Ref<Texture2D> GetIcon() const;
    [[nodiscard]] std::string GetClipboardText() const;
    [[nodiscard]] Vector2 GetPosition() const;
    [[nodiscard]] Vector2 GetSize() const;
    [[nodiscard]] std::string GetTitle() const;

    void SetFocused();
    void SetIcon(const Ref<Texture2D> &icon);
    void SetMaxSize(int width, int height);
    void SetMinSize(int width, int height);
    void SetOpacity(float opacity);
    void SetPosition(int x, int y);
    void SetSize(int width, int height);
    void SetState(WindowFlag flag);
    void SetTitle(const std::string &title);

    void ClearWindowState(WindowFlag flag);
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