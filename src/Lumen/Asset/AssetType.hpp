#pragma once

#include <string>

namespace Lumen
{

enum class AssetType
{
    None = 0,
    Animation,
    Audio,
    Font,
    Image,
    Material,
    Mesh,
    Model,
    Prefab,
    Scene,
    Script,
    Shader,
    Texture2D,
    Tilemap,
    Video,

    Folder,
    TextFile,
    JSON,
    XML,
    YAML,
    Markdown,
    CSV,
    Binary,
    Config
};

inline constexpr std::string AssetTypeToString(AssetType type)
{
    switch (type)
    {
    case AssetType::None:
        return "None";
    case AssetType::Animation:
        return "Animation";
    case AssetType::Audio:
        return "Audio";
    case AssetType::Font:
        return "Font";
    case AssetType::Image:
        return "Image";
    case AssetType::Material:
        return "Material";
    case AssetType::Mesh:
        return "Mesh";
    case AssetType::Model:
        return "Model";
    case AssetType::Prefab:
        return "Prefab";
    case AssetType::Scene:
        return "Scene";
    case AssetType::Script:
        return "Script";
    case AssetType::Shader:
        return "Shader";
    case AssetType::Texture2D:
        return "Texture2D";
    case AssetType::Tilemap:
        return "Tilemap";
    case AssetType::Video:
        return "Video";

    case AssetType::Folder:
        return "Folder";
    case AssetType::TextFile:
        return "TextFile";
    case AssetType::JSON:
        return "JSON";
    case AssetType::XML:
        return "XML";
    case AssetType::YAML:
        return "YAML";
    case AssetType::Markdown:
        return "Markdown";
    case AssetType::CSV:
        return "CSV";
    case AssetType::Binary:
        return "Binary";
    case AssetType::Config:
        return "Config";

    default:
        return "None";
    }
}

} // namespace Lumen