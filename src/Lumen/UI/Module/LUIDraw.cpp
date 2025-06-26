#include "Lumen/UI/Module/LUIDraw.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

void DrawCircle(const Vector2 &center, float radius, Color color, int segments,
                float thickness)
{
    ImGui::GetWindowDrawList()->AddCircle(
        center, radius, ImGui::GetColorU32(color.Normalize()), segments, thickness);
}

void DrawCircleFilled(const Vector2 &center, float radius, Color color, int segments)
{
    ImGui::GetWindowDrawList()->AddCircleFilled(
        center, radius, ImGui::GetColorU32(color.Normalize()), segments);
}

void DrawConvexPolyFilled(const std::vector<Vector2> &points, Color color)
{
    ImGui::GetWindowDrawList()->AddConvexPolyFilled(
        reinterpret_cast<const ImVec2 *>(points.data()), points.size(),
        ImGui::GetColorU32(color.Normalize()));
}

void DrawImage(const Texture2D &texture, const Vector2 &min, const Vector2 &max,
               const Vector2 &uv0, const Vector2 &uv1, Color tintColor)
{
    ImGui::GetWindowDrawList()->AddImage(texture.GetRendererIDPtr(), min, max, uv0, uv1,
                                         ImGui::GetColorU32(tintColor.Normalize()));
}

void DrawLine(const Vector2 &p1, const Vector2 &p2, Color color, float thickness)
{
    ImGui::GetWindowDrawList()->AddLine(p1, p2, ImGui::GetColorU32(color.Normalize()),
                                        thickness);
}

void DrawPolyline(const std::vector<Vector2> &points, Color color, bool closed,
                  float thickness)
{
    ImGui::GetWindowDrawList()->AddPolyline(
        reinterpret_cast<const ImVec2 *>(points.data()), points.size(),
        ImGui::GetColorU32(color.Normalize()), closed, thickness);
}

void DrawQuad(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3, const Vector2 &p4,
              Color color, float thickness)
{
    ImGui::GetWindowDrawList()->AddQuad(p1, p2, p3, p4,
                                        ImGui::GetColorU32(color.Normalize()), thickness);
}

void DrawQuadFilled(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3,
                    const Vector2 &p4, Color color)
{
    ImGui::GetWindowDrawList()->AddQuadFilled(p1, p2, p3, p4,
                                              ImGui::GetColorU32(color.Normalize()));
}

void DrawRectangle(const Vector2 &min, const Vector2 &max, Color color, float thickness,
                   float rounding, unsigned int roundingFlags)
{
    ImGui::GetWindowDrawList()->AddRect(min, max, ImGui::GetColorU32(color.Normalize()),
                                        rounding, roundingFlags, thickness);
}

void DrawRectFilled(const Vector2 &min, const Vector2 &max, Color color, float rounding,
                    unsigned int roundingFlags)
{
    ImGui::GetWindowDrawList()->AddRect(min, max, ImGui::GetColorU32(color.Normalize()),
                                        rounding, roundingFlags);
}

void DrawText(const Vector2 &pos, const std::string &text, Color color)
{
    ImGui::GetWindowDrawList()->AddText(pos, ImGui::GetColorU32(color.Normalize()),
                                        text.c_str(), nullptr);
}

void PathArcTo(const Vector2 &center, float radius, float min, float max, int segments)
{
    ImGui::GetWindowDrawList()->PathArcTo(center, radius, min, max);
}

void PathArcToFast(const Vector2 &center, float radius, int min, int max)
{
    ImGui::GetWindowDrawList()->PathArcToFast(center, radius, min, max);
}

void PathBezierCubicCurveTo(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3,
                            int segments)
{
    ImGui::GetWindowDrawList()->PathBezierCubicCurveTo(p1, p2, p3, segments);
}

void PathClear()
{
    ImGui::GetWindowDrawList()->PathClear();
}

void PathFillConvex(Color color)
{
    ImGui::GetWindowDrawList()->PathFillConvex(ImGui::GetColorU32(color.Normalize()));
}

void PathLineTo(const Vector2 &pos)
{
    ImGui::GetWindowDrawList()->PathLineTo(pos);
}

void PathStroke(Color color, bool closed, float thickness)
{
    ImGui::GetWindowDrawList()->PathStroke(ImGui::GetColorU32(color.Normalize()), closed,
                                           thickness);
}

} // namespace Lumen::LUI