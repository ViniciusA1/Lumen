#include "Lumen/Math/BoundingBox.hpp"
#include "Lumen/Math/Rectangle.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector4.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterBoundingBox();
static void RegisterMath();
static void RegisterMatrix4();
static void RegisterQuaternion();
static void RegisterRectangle();
static void RegisterVector2();
static void RegisterVector3();
static void RegisterVector4();

void RegisterMathAPI()
{
    RegisterBoundingBox();
    RegisterMath();
    RegisterMatrix4();
    RegisterQuaternion();
    RegisterRectangle();
    RegisterVector2();
    RegisterVector3();
    RegisterVector4();
}

static void RegisterBoundingBox()
{
    ScriptEngine::GetInstance()
        ->RegisterType<BoundingBox>("BoundingBox")
        .Constructors<BoundingBox(), BoundingBox(const Vector3 &, const Vector3 &)>()
        .Property("min", &BoundingBox::Min)
        .Property("max", &BoundingBox::Max)
        .Property("center", &BoundingBox::GetCenter)
        .Property("extents", &BoundingBox::GetExtents)
        .Property("size", &BoundingBox::GetSize)
        .Property("surface_area", &BoundingBox::GetSurfaceArea)
        .Property("volume", &BoundingBox::GetVolume)
        .Method("is_valid", &BoundingBox::IsValid)
        .Method(
            "contains",
            [](const BoundingBox &self, const Vector3 &point) {
                return self.Contains(point);
            },
            [](const BoundingBox &self, const BoundingBox &other) {
                return self.Contains(other);
            })
        .Method("intersects", &BoundingBox::Intersects)
        .Method("corner", &BoundingBox::GetCorner)
        .Method("transform", &BoundingBox::Transform);
}

static void RegisterMath()
{
    auto mathType = ScriptEngine::GetInstance()->RegisterType<Math>("Math");

    ScriptEngine::GetInstance()
        ->RegisterType<Math>("Math")
        .StaticProperty("pi", Math::PI)
        .StaticProperty("to_rad", Math::Deg2Rad)
        .StaticProperty("to_deg", Math::Rad2Deg)
        .StaticProperty("epsilon", Math::Epsilon)
        .StaticProperty("infinity", Math::Infinity)
        .StaticProperty("negative_infinity", Math::NegativeInfinity)
        .StaticMethod("abs", &Math::Abs)
        .StaticMethod("fmod", &Math::Fmod)
        .StaticMethod("max", static_cast<float (*)(float, float)>(&Math::Max),
                      static_cast<float (*)(std::initializer_list<float>)>(&Math::Max))
        .StaticMethod("min", static_cast<float (*)(float, float)>(&Math::Min),
                      static_cast<float (*)(std::initializer_list<float>)>(&Math::Min))
        .StaticMethod("pow", &Math::Pow)
        .StaticMethod("exp", &Math::Exp)
        .StaticMethod("sqrt", &Math::Sqrt)
        .StaticMethod("ceil", &Math::Ceil)
        .StaticMethod("ceil_to_int", &Math::CeilToInt)
        .StaticMethod("floor", &Math::Floor)
        .StaticMethod("floor_to_int", &Math::FloorToInt)
        .StaticMethod("round", &Math::Round)
        .StaticMethod("round_to_int", &Math::RoundToInt)
        .StaticMethod("cos", &Math::Cos)
        .StaticMethod("sin", &Math::Sin)
        .StaticMethod("tan", &Math::Tan)
        .StaticMethod("acos", &Math::Acos)
        .StaticMethod("asin", &Math::Asin)
        .StaticMethod("atan", &Math::Atan)
        .StaticMethod("atan2", &Math::Atan2)
        .StaticMethod("lerp", &Math::Lerp)
        .StaticMethod("lerp_unclamped", &Math::LerpUnclamped)
        .StaticMethod("inverse_lerp", &Math::InverseLerp)
        .StaticMethod("move_towards", &Math::MoveTowards)
        .StaticMethod("delta_angle", &Math::DeltaAngle)
        .StaticMethod("clamp", &Math::Clamp)
        .StaticMethod("clamp01", &Math::Clamp01)
        .StaticMethod("repeat", &Math::Repeat)
        .StaticMethod("approximately", &Math::Approximately)
        .StaticMethod("is_power_of_two", &Math::IsPowerOfTwo)
        .StaticMethod("log", &Math::Log)
        .StaticMethod("log10", &Math::Log10)
        .StaticMethod("sign", &Math::Sign)
        .StaticMethod("smooth_step", &Math::SmoothStep);
}

static void RegisterMatrix4()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Matrix4>("Matrix4")
        .Constructors<Matrix4(), Matrix4(float), Matrix4(std::initializer_list<float>)>()
        .StaticProperty("Identity", Matrix4::Identity)
        .StaticProperty("Zero", Matrix4::Zero)
        .Property("determinant", &Matrix4::Determinant)
        .Property("inverse", &Matrix4::Inverse)
        .Property("trace", &Matrix4::Trace)
        .Property("transpose", &Matrix4::Transpose)
        .StaticMethod("decompose_transform", &Matrix4::DecomposeTransform)
        .StaticMethod("decompose_view", &Matrix4::DecomposeView)
        .StaticMethod("frustum", &Matrix4::Frustum)
        .StaticMethod("look_at", &Matrix4::LookAt)
        .StaticMethod("ortho", &Matrix4::Ortho)
        .StaticMethod("perspective", &Matrix4::Perspective)
        .StaticMethod("rotate", &Matrix4::Rotate)
        .StaticMethod("rotate_x", &Matrix4::RotateX)
        .StaticMethod("rotate_y", &Matrix4::RotateY)
        .StaticMethod("rotate_z", &Matrix4::RotateZ)
        .StaticMethod("rotate_xyz", &Matrix4::RotateXYZ)
        .StaticMethod("rotate_zyx", &Matrix4::RotateZYX)
        .StaticMethod("scale",
                      static_cast<Matrix4 (*)(float, float, float)>(&Matrix4::Scale),
                      static_cast<Matrix4 (*)(const Vector3 &)>(&Matrix4::Scale))
        .StaticMethod("transform", &Matrix4::Transform)
        .StaticMethod("translate",
                      static_cast<Matrix4 (*)(float, float, float)>(&Matrix4::Translate),
                      static_cast<Matrix4 (*)(const Vector3 &)>(&Matrix4::Translate))
        .OperatorAdd([](const Matrix4 &a, const Matrix4 &b) { return a + b; })
        .OperatorSub([](const Matrix4 &a, const Matrix4 &b) { return a - b; })
        .OperatorMul([](const Matrix4 &a, const Matrix4 &b) { return a * b; })
        .OperatorMul([](const Matrix4 &a, float scalar) { return a * scalar; })
        .OperatorIndex([](const Matrix4 &matrix, size_t index) { return matrix[index]; })
        .OperatorNewIndex([](Matrix4 &matrix, size_t index) { return matrix[index]; });
}

static void RegisterQuaternion()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Quaternion>("Quaternion")
        .Constructors<Quaternion(), Quaternion(float, float, float, float)>()
        .StaticProperty("identity", Quaternion::Identity)
        .Property("x", &Quaternion::x)
        .Property("y", &Quaternion::y)
        .Property("z", &Quaternion::z)
        .Property("w", &Quaternion::w)
        .Property("inverted", &Quaternion::Inverted)
        .Property("length", &Quaternion::Length)
        .Property("normalized", &Quaternion::Normalized)
        .Property("matrix", &Quaternion::ToMatrix)
        .Property("euler", &Quaternion::ToEuler)
        .Property("axis_angle", &Quaternion::ToAxisAngle)
        .Method("transformed", &Quaternion::Transformed)
        .StaticMethod("from_axis_angle", &Quaternion::FromAxisAngle)
        .StaticMethod("from_euler", &Quaternion::FromEuler)
        .StaticMethod("from_matrix", &Quaternion::FromMatrix)
        .StaticMethod("from_vector3_to_vector3", &Quaternion::FromVector3ToVector3)
        .StaticMethod("lerp", &Quaternion::Lerp)
        .StaticMethod("nlerp", &Quaternion::Nlerp)
        .StaticMethod("slerp", &Quaternion::Slerp)
        .OperatorAdd([](const Quaternion &a, const Quaternion &b) { return a + b; },
                     [](const Quaternion &a, float value) { return a + value; })
        .OperatorSub([](const Quaternion &a, const Quaternion &b) { return a - b; },
                     [](const Quaternion &a, float value) { return a - value; })
        .OperatorMul([](const Quaternion &a, const Quaternion &b) { return a * b; },
                     [](const Quaternion &a, float scalar) { return a * scalar; },
                     [](float scalar, const Quaternion &a) { return scalar * a; })
        .OperatorDiv([](const Quaternion &a, const Quaternion &b) { return a / b; })
        .OperatorEq([](const Quaternion &a, const Quaternion &b) { return a == b; });
}

static void RegisterRectangle()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Rectangle>("Rectangle")
        .Constructors<Rectangle(float, float, float, float),
                      Rectangle(const Vector2 &, const Vector2 &)>()
        .Property("x", &Rectangle::x)
        .Property("y", &Rectangle::y)
        .Property("width", &Rectangle::Width)
        .Property("height", &Rectangle::Height)
        .Property("center", &Rectangle::GetCenter)
        .Property("position", &Rectangle::GetPosition)
        .Property("size", &Rectangle::GetSize)
        .Method("set_position", &Rectangle::SetPosition)
        .Method("set_size", &Rectangle::SetSize)
        .Method("contains", &Rectangle::Contains)
        .Method("intersects", &Rectangle::Intersects);
}

static void RegisterVector2()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Vector2>("Vector2")
        .Constructors<Vector2(), Vector2(float, float)>()
        .StaticProperty("one", Vector2::One)
        .StaticProperty("zero", Vector2::Zero)
        .Property("x", &Vector2::x)
        .Property("y", &Vector2::y)
        .Property("length", &Vector2::Length)
        .Property("length_sqr", &Vector2::LengthSqr)
        .Property("normalized", &Vector2::Normalized)
        .StaticMethod("angle", &Vector2::Angle)
        .StaticMethod(
            "clamp",
            static_cast<Vector2 (*)(const Vector2 &, const Vector2 &, const Vector2 &)>(
                &Vector2::Clamp),
            static_cast<Vector2 (*)(const Vector2 &, float, float)>(&Vector2::Clamp))
        .StaticMethod("distance", &Vector2::Distance)
        .StaticMethod("distance_sqr", &Vector2::DistanceSqr)
        .StaticMethod("dot", &Vector2::Dot)
        .StaticMethod("lerp", &Vector2::Lerp)
        .StaticMethod("move_towards", &Vector2::MoveTowards)
        .StaticMethod("reflect", &Vector2::Reflect)
        .StaticMethod("rotate", &Vector2::Rotate)
        .StaticMethod("transform", &Vector2::Transform)
        .OperatorAdd([](const Vector2 &a, const Vector2 &b) { return a + b; })
        .OperatorSub([](const Vector2 &a, const Vector2 &b) { return a - b; })
        .OperatorMul([](const Vector2 &a, float scalar) { return a * scalar; },
                     [](float scalar, const Vector2 &a) { return scalar * a; })
        .OperatorDiv([](const Vector2 &a, float scalar) { return a / scalar; })
        .OperatorEq([](const Vector2 &a, const Vector2 &b) { return a == b; })
        .OperatorUnaryMinus([](const Vector2 &a) { return -a; });
}

static void RegisterVector3()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Vector3>("Vector3")
        .Constructors<Vector3(), Vector3(float, float, float)>()
        .StaticProperty("one", Vector3::One)
        .StaticProperty("zero", Vector3::Zero)
        .Property("x", &Vector3::x)
        .Property("y", &Vector3::y)
        .Property("z", &Vector3::z)
        .Property("length", &Vector3::Length)
        .Property("length_sqr", &Vector3::LengthSqr)
        .Property("normalized", &Vector3::Normalized)
        .StaticMethod("angle", &Vector3::Angle)
        .StaticMethod(
            "clamp",
            static_cast<Vector3 (*)(const Vector3 &, const Vector3 &, const Vector3 &)>(
                &Vector3::Clamp),
            static_cast<Vector3 (*)(const Vector3 &, float, float)>(&Vector3::Clamp))
        .StaticMethod("cross", &Vector3::Cross)
        .StaticMethod("dot", &Vector3::Dot)
        .StaticMethod("distance", &Vector3::Distance)
        .StaticMethod("distance_sqr", &Vector3::DistanceSqr)
        .StaticMethod("forward", &Vector3::Forward)
        .StaticMethod("lerp", &Vector3::Lerp)
        .StaticMethod("max", &Vector3::Max)
        .StaticMethod("min", &Vector3::Min)
        .StaticMethod("orthonormalize", &Vector3::OrthoNormalize)
        .StaticMethod("reflect", &Vector3::Reflect)
        .StaticMethod("refract", &Vector3::Refract)
        .StaticMethod("right", &Vector3::Right)
        .StaticMethod("rotate_by_axis_angle", &Vector3::RotateByAxisAngle)
        .StaticMethod("rotate_by_quaternion", &Vector3::RotateByQuaternion)
        .StaticMethod("transform", &Vector3::Transform)
        .StaticMethod("up", &Vector3::Up)
        .OperatorAdd([](const Vector3 &a, const Vector3 &b) { return a + b; })
        .OperatorSub([](const Vector3 &a, const Vector3 &b) { return a - b; })
        .OperatorMul([](const Vector3 &a, float scalar) { return a * scalar; },
                     [](float scalar, const Vector3 &a) { return scalar * a; })
        .OperatorDiv([](const Vector3 &a, float scalar) { return a / scalar; })
        .OperatorEq([](const Vector3 &a, const Vector3 &b) { return a == b; })
        .OperatorUnaryMinus([](const Vector3 &a) { return -a; });
}

static void RegisterVector4()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Vector4>("Vector4")
        .Constructors<Vector4(), Vector4(float, float, float, float)>()
        .StaticProperty("one", Vector4::One)
        .StaticProperty("zero", Vector4::Zero)
        .Property("x", &Vector4::x)
        .Property("y", &Vector4::y)
        .Property("z", &Vector4::z)
        .Property("w", &Vector4::w)
        .Property("length", &Vector4::Length)
        .Property("length_sqr", &Vector4::LengthSqr)
        .Property("normalized", &Vector4::Normalized)
        .StaticMethod("distance", &Vector4::Distance)
        .StaticMethod("distance_sqr", &Vector4::DistanceSqr)
        .StaticMethod("dot", &Vector4::Dot)
        .StaticMethod("lerp", &Vector4::Lerp)
        .StaticMethod("max", &Vector4::Max)
        .StaticMethod("min", &Vector4::Min)
        .StaticMethod("move_towards", &Vector4::MoveTowards)
        .OperatorAdd([](const Vector4 &a, const Vector4 &b) { return a + b; })
        .OperatorSub([](const Vector4 &a, const Vector4 &b) { return a - b; })
        .OperatorMul([](const Vector4 &a, float scalar) { return a * scalar; },
                     [](float scalar, const Vector4 &a) { return scalar * a; })
        .OperatorDiv([](const Vector4 &a, float scalar) { return a / scalar; })
        .OperatorEq([](const Vector4 &a, const Vector4 &b) { return a == b; })
        .OperatorUnaryMinus([](const Vector4 &a) { return -a; });
}

} // namespace Lumen