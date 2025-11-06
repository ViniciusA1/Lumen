#include "Lumen/Asset/Importer/AudioImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Music Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    return ::LoadMusicStream(metadata.Path.String().c_str());
}

template <> bool Export(const Music &music)
{
    if (!music.IsValid())
        return false;

    ::Music *rayMusic = music;
    ::UnloadMusicStream(*rayMusic);
    delete rayMusic;
    return true;
}

template <> Sound Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    return ::LoadSound(metadata.Path.String().c_str());
}

template <> bool Export(const Sound &sound)
{
    if (!sound.IsValid())
        return false;

    ::Sound *raySound = sound;
    ::UnloadSound(*raySound);
    delete raySound;
    return true;
}

template <> Wave Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    return ::LoadWave(metadata.Path.String().c_str());
}

template <> bool Export(const Wave &wave)
{
    if (!wave.IsValid())
        return false;

    ::Wave *rayWave = wave;
    ::UnloadWave(*rayWave);
    delete rayWave;
    return true;
}

} // namespace Lumen::AssetImporter