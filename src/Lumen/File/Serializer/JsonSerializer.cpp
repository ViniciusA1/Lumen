#include "Lumen/File/Serializer/JsonSerializer.hpp"

#include <fstream>

namespace Lumen
{

Json::Json(nlohmann::json j) : m_Data(std::move(j))
{
}

Json::Json(std::initializer_list<nlohmann::json::value_type> initList) : m_Data(initList)
{
}

bool Json::IsNull() const
{
    return m_Data.is_null();
}

bool Json::IsObject() const
{
    return m_Data.is_object();
}

bool Json::IsArray() const
{
    return m_Data.is_array();
}

bool Json::IsString() const
{
    return m_Data.is_string();
}

bool Json::IsNumber() const
{
    return m_Data.is_number();
}

bool Json::IsBoolean() const
{
    return m_Data.is_boolean();
}

bool Json::Contains(const std::string &key) const
{
    return m_Data.contains(key);
}

void Json::Clear()
{
    m_Data.clear();
}

void Json::Erase(const std::string &key)
{
    m_Data.erase(key);
}

std::vector<std::string> Json::Keys() const
{
    if (!IsObject())
    {
        return {};
    }

    std::vector<std::string> result;
    for (const auto &item : m_Data.items())
    {
        result.push_back(item.key());
    }

    return result;
}

std::size_t Json::Size() const
{
    return m_Data.size();
}

std::vector<Json> Json::Values() const
{
    if (!IsObject())
    {
        return {};
    }

    std::vector<Json> result;
    for (const auto &item : m_Data.items())
    {
        result.emplace_back(item.value());
    }

    return result;
}

Json Json::FromFile(const Path &path)
{
    std::ifstream file(path.String());
    if (!file.is_open())
    {
        return {};
    }

    nlohmann::json jsonData;
    file >> jsonData;
    return jsonData;
}

bool Json::ToFile(const Path &path, int indent)
{
    std::ofstream file(path.String());
    if (!file.is_open())
    {
        return false;
    }

    file << m_Data.dump(indent);
    return true;
}

Json::operator nlohmann::json() const
{
    return m_Data;
}

} // namespace Lumen