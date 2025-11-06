#pragma once

#include "Lumen/System/UUID.hpp"

namespace Lumen
{

enum class CanvasRenderMode
{
    ScreenSpaceOverlay,
    ScreenSpaceCamera,
    WorldSpace
};

struct CanvasComponent
{
    CanvasRenderMode Mode = CanvasRenderMode::ScreenSpaceOverlay;
    UUID CameraID = 0;
    float ScaleFactor = 1.0f;
    int SortingOrder = 0;
};

} // namespace Lumen