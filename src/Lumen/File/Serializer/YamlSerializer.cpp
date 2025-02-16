#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include <fstream>

namespace Lumen
{

Yaml::Yaml(const YAML::Node &node) : m_Data(node)
{
}

bool Yaml::IsNull() const
{
    return m_Data.IsNull();
}

bool Yaml::IsSequence() const
{
    return m_Data.IsSequence();
}

void Yaml::Clear()
{
    m_Data.reset();
}

bool Yaml::Contains(const std::string &key) const
{
    return m_Data[key] && m_Data[key].IsDefined();
}

std::size_t Yaml::Size() const
{
    return m_Data.size();
}

void Yaml::SetStyle(Yaml::EmitterStyle style)
{
    m_Data.SetStyle(static_cast<YAML::EmitterStyle::value>(style));
}

void Yaml::PushBack(const Yaml &yaml)
{
    m_Data.push_back(yaml.m_Data);
}

Yaml Yaml::FromFile(const Path &path)
{
    std::ifstream file(path.String());
    if (!file.is_open())
    {
        return {};
    }

    YAML::Node node;
    try
    {
        node = YAML::Load(file);
    }
    catch (const YAML::ParserException &e)
    {
        return {};
    }

    return node;
}

bool Yaml::ToFile(const Path &path)
{
    std::ofstream file(path.String());
    if (!file.is_open())
    {
        return false;
    }

    file << m_Data;
    return true;
}

Yaml::ConstIterator Yaml::begin() const
{
    return ConstIterator(m_Data.begin());
}

Yaml::ConstIterator Yaml::end() const
{
    return ConstIterator(m_Data.end());
}

Yaml::Iterator Yaml::begin()
{
    return Iterator(m_Data.begin());
}

Yaml::Iterator Yaml::end()
{
    return Iterator(m_Data.end());
}

Yaml::operator YAML::Node() const
{
    return m_Data;
}

} // namespace Lumen