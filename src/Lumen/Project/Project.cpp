#include "Lumen/Project/Project.hpp"

namespace Lumen
{

bool Project::IsValid() const
{
    return !Name.empty();
}

bool Project::operator==(const Project &other) const
{
    return Name == other.Name && RootDirectory == other.RootDirectory;
}

} // namespace Lumen