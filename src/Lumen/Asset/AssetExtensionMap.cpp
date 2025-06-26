#include "Lumen/Asset/AssetExtensionMap.hpp"

namespace Lumen
{

std::unordered_map<std::string, AssetType> AssetExtensionMap::s_Extensions = {
    // Audio
    {".mp3", AssetType::Audio},
    {".wav", AssetType::Audio},
    {".ogg", AssetType::Audio},
    {".flac", AssetType::Audio},

    // Font
    {".ttf", AssetType::Font},
    {".otf", AssetType::Font},
    {".fnt", AssetType::Font},

    // Material
    {".mat", AssetType::Material},

    // Mesh
    {".mesh", AssetType::Mesh},

    // Model
    {".fbx", AssetType::Model},
    {".gltf", AssetType::Model},
    {".glb", AssetType::Model},
    {".obj", AssetType::Model},

    // Prefab
    {".prefab", AssetType::Prefab},

    // Scene
    {".lscene", AssetType::Scene},

    // Script
    {".cpp", AssetType::Script},
    {".lua", AssetType::Script},
    {".cs", AssetType::Script},
    {".js", AssetType::Script},

    // Shader
    {".vert", AssetType::Shader},
    {".frag", AssetType::Shader},
    {".shader", AssetType::Shader},
    {".hlsl", AssetType::Shader},
    {".glsl", AssetType::Shader},

    // Texture
    {".jpg", AssetType::Texture2D},
    {".jpeg", AssetType::Texture2D},
    {".png", AssetType::Texture2D},
    {".bmp", AssetType::Texture2D},
    {".tga", AssetType::Texture2D},
    {".dds", AssetType::Texture2D},
    {".ktx", AssetType::Texture2D},
    {".hdr", AssetType::Texture2D},

    // Tilemap
    {".tilemap", AssetType::Tilemap},
    {".tmx", AssetType::Tilemap},

    // Video
    {".mp4", AssetType::Video},
    {".webm", AssetType::Video},
    {".avi", AssetType::Video},
    {".mov", AssetType::Video},

    // General file types
    {".txt", AssetType::TextFile},
    {".md", AssetType::Markdown},
    {".json", AssetType::JSON},
    {".xml", AssetType::XML},
    {".yaml", AssetType::YAML},
    {".yml", AssetType::YAML},
    {".csv", AssetType::CSV},
    {".bin", AssetType::Binary},
    {".cfg", AssetType::Config},
    {".ini", AssetType::Config},
    {".lconfig", AssetType::Config},
};

bool AssetExtensionMap::HasExtension(const std::string &extension)
{
    return s_Extensions.contains(extension);
}

AssetType AssetExtensionMap::GetAssetType(const std::string &extension)
{
    auto it = s_Extensions.find(extension);
    if (it == s_Extensions.end())
        return AssetType::None;

    return it->second;
}

void AssetExtensionMap::RegisterExtension(const std::string &extension, AssetType type)
{
    if (HasExtension(extension))
        return;

    s_Extensions[extension] = type;
}

void AssetExtensionMap::UnregisterExtension(const std::string &extension)
{
    auto it = s_Extensions.find(extension);
    if (it != s_Extensions.end())
        s_Extensions.erase(it);
}

} // namespace Lumen