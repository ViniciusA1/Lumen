#pragma once

#include "Lumen/Asset/AssetImporter.hpp"

namespace Lumen
{

class DefaultAudioImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultFontImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultMaterialImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultMeshImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultModelImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultPrefabImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultSceneImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultScriptImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultShaderImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

class DefaultTexture2DImporter : public DefaultAssetImporter
{
public:
    Scope<Asset> Import() override;
};

} // namespace Lumen