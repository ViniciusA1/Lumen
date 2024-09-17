#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Math/Matrix.hpp"
#include "Lumen/Math/Vector.hpp"
#include <string>

namespace Lumen
{

class Renderer
{
public:
    static void BeginDrawing();
    static void EndDrawing();

    static void Clear();
    static void SetClearColor(const Color &color) { s_Color = color; }

    static void DrawQuad(const Vector2 &position, const Vector2 &size,
                         const Color &color);
    static void DrawQuad(const Matrix4 &transform, const Color &color);

    static void DrawText(const std::string &text, const Vector2 &position, int fontSize,
                         const Color &color);
    static void DrawFPS(const Vector2 &position, int fontSize, const Color &color);

private:
    static Color s_Color;
};

} // namespace Lumen