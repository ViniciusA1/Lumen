#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ProgressBarComponent &progressBar)
{
    Json json, progressBarJson;
    progressBarJson = Serialize(static_cast<const UIComponentBase &>(progressBar));
    progressBarJson["MaxValue"] << progressBar.MaxValue;
    progressBarJson["Value"] << progressBar.Value;
    progressBarJson["BackgroundColor"] << progressBar.BackgroundColor;
    json["ProgressBar"] << progressBarJson;
    return json;
}

template <> void Deserialize(const Json &json, ProgressBarComponent &progressBar)
{
    const Json &progressBarJson = json["ProgressBar"];
    Deserialize(progressBarJson, static_cast<UIComponentBase &>(progressBar));
    progressBarJson["MaxValue"] >> progressBar.MaxValue;
    progressBarJson["Value"] >> progressBar.Value;
    progressBarJson["BackgroundColor"] >> progressBar.BackgroundColor;
}

} // namespace Lumen::JsonSerializer