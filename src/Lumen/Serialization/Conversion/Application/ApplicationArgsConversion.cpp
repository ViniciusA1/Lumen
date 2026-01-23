#include "Lumen/Serialization/Conversion/Application/ApplicationConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ApplicationArgs &args)
{
    Json json;

    json["Title"] << args.Title;
    json["Resolution"] << args.Resolution;
    json["Icon"] << args.Icon;
    json["Flags"] << args.Flags;
    json["TargetFPS"] << args.TargetFPS;
    json["WorkingDirectory"] << args.WorkingDirectory;
    json["AssetDirectory"] << args.AssetDirectory;
    json["SceneDirectory"] << args.SceneDirectory;
    json["StartScene"] << args.StartScene;

    return json;
}

template <> void Deserialize(const Json &json, ApplicationArgs &args)
{
    json["Title"] >> args.Title;
    json["Resolution"] >> args.Resolution;
    json["Icon"] >> args.Icon;
    json["Flags"] >> args.Flags;
    json["TargetFPS"] >> args.TargetFPS;
    json["WorkingDirectory"] >> args.WorkingDirectory;
    json["AssetDirectory"] >> args.AssetDirectory;
    json["SceneDirectory"] >> args.SceneDirectory;
    json["StartScene"] >> args.StartScene;
}

} // namespace Lumen::JsonSerializer