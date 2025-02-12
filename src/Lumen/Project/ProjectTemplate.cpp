#include "Lumen/Project/ProjectTemplate.hpp"

namespace Lumen
{

bool ProjectTemplate::operator==(const ProjectTemplate &other) const
{
    return RootDirectory == other.RootDirectory && Name == other.Name;
}

} // namespace Lumen