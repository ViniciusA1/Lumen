#pragma once

#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Vector2.hpp"

#include <string>
#include <vector>

namespace Lumen::LUI
{

void DrawCircle(const Vector2 &center, float radius, Color color, int segments = 0,
                float thickness = 1.0f);
void DrawCircleFilled(const Vector2 &center, float radius, Color color, int segments = 0);

void DrawConvexPolyFilled(const std::vector<Vector2> &points, Color color);

void DrawImage(const Texture2D &texture, const Vector2 &min, const Vector2 &max,
               const Vector2 &uv0 = {0, 0}, const Vector2 &uv1 = {1, 1},
               Color tintColor = Color::White);

void DrawLine(const Vector2 &p1, const Vector2 &p2, Color color, float thickness = 1.0f);

void DrawPolyline(const std::vector<Vector2> &points, Color color, bool closed,
                  float thickness = 1.0f);

void DrawQuad(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3, const Vector2 &p4,
              Color color, float thickness = 1.0f);
void DrawQuadFilled(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3,
                    const Vector2 &p4, Color color);

void DrawRectangle(const Vector2 &min, const Vector2 &max, Color color,
                   float thickness = 1.0f, float rounding = 0.0f,
                   unsigned int roundingFlags = 0);
void DrawRectFilled(const Vector2 &min, const Vector2 &max, Color color,
                    float rounding = 0.0f, unsigned int roundingFlags = 0);

void DrawText(const Vector2 &pos, const std::string &text, Color color);

void PathArcTo(const Vector2 &center, float radius, float min, float max,
               int segments = 10);
void PathArcToFast(const Vector2 &center, float radius, int min, int max);

void PathBezierCubicCurveTo(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3,
                            int segments = 0);

void PathClear();

void PathFillConvex(Color color);

void PathLineTo(const Vector2 &pos);

void PathStroke(Color color, bool closed, float thickness = 1.0f);

} // namespace Lumen::LUI