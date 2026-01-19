#include "Lumen/Script/Register/RegisterAPI.hpp"

namespace Lumen
{

void RegisterAllAPI()
{
    RegisterApplicationAPI();
    RegisterAssetAPI();
    RegisterAudioAPI();
    RegisterContainerAPI();
    RegisterEventAPI();
    RegisterFileAPI();
    RegisterGraphicsAPI();
    RegisterInputAPI();
    RegisterLogAPI();
    RegisterMathAPI();
    RegisterNetworkAPI();
    RegisterPhysics2DAPI();
    RegisterPhysics3DAPI();
    RegisterProjectAPI();
    RegisterRandomAPI();
    RegisterSceneAPI();
    RegisterSystemAPI();
    RegisterUIAPI();
}

} // namespace Lumen