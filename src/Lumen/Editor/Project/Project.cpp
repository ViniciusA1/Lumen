#include "Lumen/Editor/Project/Project.hpp"

namespace Lumen
{

Project::Project(ProjectConfig config) : m_Config(std::move(config))
{
}

} // namespace Lumen