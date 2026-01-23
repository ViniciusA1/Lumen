#pragma once

#include "Lumen/Serialization/Json.hpp"

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