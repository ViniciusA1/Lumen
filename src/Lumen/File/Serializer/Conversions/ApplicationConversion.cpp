#include "Lumen/File/Serializer/Conversions/ApplicationConversion.hpp"

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const WindowFlags &flags)
{
    Yaml yaml;
    yaml << static_cast<int>(flags);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, WindowFlags &flags)
{
    int value;
    yaml >> value;
    flags = static_cast<WindowFlags>(value);
}

template <> Yaml Serialize(const ApplicationArgs &args)
{
    Yaml yaml;

    yaml["Title"] << args.Title;
    yaml["Resolution"] << args.Resolution;
    yaml["Icon"] << args.Icon;
    yaml["Flags"] << args.Flags;
    yaml["TargetFPS"] << args.TargetFPS;
    yaml["WorkingDirectory"] << args.WorkingDirectory;
    yaml["AssetDirectory"] << args.AssetDirectory;
    yaml["SceneDirectory"] << args.SceneDirectory;
    yaml["StartScene"] << args.StartScene;

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ApplicationArgs &args)
{
    yaml["Title"] >> args.Title;
    yaml["Resolution"] >> args.Resolution;
    yaml["Icon"] >> args.Icon;
    yaml["Flags"] >> args.Flags;
    yaml["TargetFPS"] >> args.TargetFPS;
    yaml["WorkingDirectory"] >> args.WorkingDirectory;
    yaml["AssetDirectory"] >> args.AssetDirectory;
    yaml["SceneDirectory"] >> args.SceneDirectory;
    yaml["StartScene"] >> args.StartScene;
}

} // namespace Lumen::YamlSerializer