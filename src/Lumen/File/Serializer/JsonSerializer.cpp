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

Json::Iterator::Iterator(nlohmann::json::iterator it) : m_Iterator(std::move(it))
{
}

Json::Iterator &Json::Iterator::operator++()
{
    ++m_Iterator;
    return *this;
}

Json::Iterator Json::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

bool Json::Iterator::operator==(const Json::Iterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool Json::Iterator::operator!=(const Json::Iterator &other) const
{
    return !(*this == other);
}

Json Json::Iterator::operator*() const
{
    return *m_Iterator;
}

Json::ConstIterator::ConstIterator(nlohmann::json::const_iterator it)
    : m_Iterator(std::move(it))
{
}

Json::ConstIterator &Json::ConstIterator::operator++()
{
    ++m_Iterator;
    return *this;
}

Json::ConstIterator Json::ConstIterator::operator++(int)
{
    ConstIterator temp = *this;
    ++(*this);
    return temp;
}

bool Json::ConstIterator::operator==(const Json::ConstIterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool Json::ConstIterator::operator!=(const Json::ConstIterator &other) const
{
    return !(*this == other);
}

Json Json::ConstIterator::operator*() const
{
    return *m_Iterator;
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