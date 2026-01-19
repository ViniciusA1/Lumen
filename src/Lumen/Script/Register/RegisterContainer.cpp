#include "Lumen/Script/Register/RegisterAPI.hpp"

namespace Lumen
{

static void RegisterArray();
static void RegisterVector();

void RegisterContainerAPI()
{
    RegisterArray();
    RegisterVector();
}

static void RegisterArray()
{
}

static void RegisterVector()
{
}

} // namespace Lumen