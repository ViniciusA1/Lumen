#pragma once

#include "Lumen/File/Serializer/JsonSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Quaternion.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Vector2 &vec);
template <> void Deserialize(const Json &json, Vector2 &vec);

template <> Json Serialize(const Vector3 &vec);
template <> void Deserialize(const Json &json, Vector3 &vec);

template <> Json Serialize(const Vector4 &vec);
template <> void Deserialize(const Json &json, Vector4 &vec);

template <> Json Serialize(const Quaternion &quat);
template <> void Deserialize(const Json &json, Quaternion &quat);

template <> Json Serialize(const Matrix4 &mat);
template <> void Deserialize(const Json &json, Matrix4 &mat);

template <> Json Serialize(const Rectangle &rect);
template <> void Deserialize(const Json &json, Rectangle &rect);

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Vector2 &vec);
template <> void Deserialize(const Yaml &yaml, Vector2 &vec);

template <> Yaml Serialize(const Vector3 &vec);
template <> void Deserialize(const Yaml &yaml, Vector3 &vec);

template <> Yaml Serialize(const Vector4 &vec);
template <> void Deserialize(const Yaml &yaml, Vector4 &vec);

template <> Yaml Serialize(const Quaternion &quat);
template <> void Deserialize(const Yaml &yaml, Quaternion &quat);

template <> Yaml Serialize(const Matrix4 &mat);
template <> void Deserialize(const Yaml &yaml, Matrix4 &mat);

template <> Yaml Serialize(const Rectangle &rect);
template <> void Deserialize(const Yaml &yaml, Rectangle &rect);

} // namespace Lumen::YamlSerializer