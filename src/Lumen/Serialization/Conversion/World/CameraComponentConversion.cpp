#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const CameraComponent &camera)
{
    Json json, cameraJson;
    cameraJson["Fov"] << camera.Fov;
    cameraJson["Projection"] << static_cast<int>(camera.Projection);
    json["Camera"] << cameraJson;
    return json;
}

template <> void Deserialize(const Json &json, CameraComponent &camera)
{
    const Json &cameraJson = json["Camera"];
    cameraJson["Fov"] >> camera.Fov;
    int projection;
    cameraJson["Projection"] >> projection;
    camera.Projection = static_cast<ProjectionType>(projection);
}

} // namespace Lumen::JsonSerializer