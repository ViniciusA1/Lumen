#include "Lumen/Asset/Importer/AudioImporter.hpp"
#include "Lumen/Audio/AudioEngine.hpp"

#include "miniaudio.h"

namespace Lumen::AssetImporter
{

template <> Audio Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    Audio audio = AudioEngine::LoadAudio(metadata.Path);
    return audio;
}

template <> bool Export(const Audio &audio)
{
    if (!audio.IsValid())
        return false;

    ma_sound sound = audio;
    AudioEngine::UnloadAudio(sound);
    ma_sound *soundPtr = audio;
    delete soundPtr;
    return true;
}

} // namespace Lumen::AssetImporter