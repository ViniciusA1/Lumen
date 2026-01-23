#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const CanvasComponent &canvas)
{
    Json json, canvasJson;
    canvasJson["Mode"] << static_cast<int>(canvas.Mode);
    canvasJson["Camera"] << canvas.CameraID;
    canvasJson["ScaleFactor"] << canvas.ScaleFactor;
    canvasJson["SortOrder"] << canvas.SortingOrder;
    json["Canvas"] << canvasJson;
    return json;
}

template <> void Deserialize(const Json &json, CanvasComponent &canvas)
{
    const Json &canvasJson = json["Canvas"];
    int modeInt;
    canvasJson["Mode"] >> modeInt;
    canvas.Mode = static_cast<CanvasRenderMode>(modeInt);
    canvasJson["Camera"] >> canvas.CameraID;
    canvasJson["ScaleFactor"] >> canvas.ScaleFactor;
    canvasJson["SortOrder"] >> canvas.SortingOrder;
}

} // namespace Lumen::JsonSerializer