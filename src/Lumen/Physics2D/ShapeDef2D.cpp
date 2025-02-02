#include "Lumen/Physics2D/ShapeDef2D.hpp"

#include "box2d/types.h"

namespace Lumen
{

ShapeFilter2D::operator b2Filter() const
{
    return {CategoryBits, MaskBits, GroupIndex};
}

ShapeDef2D::ShapeDef2D() : ShapeDef2D(b2DefaultShapeDef())
{
}

ShapeDef2D::ShapeDef2D(const b2ShapeDef &def)
{
    Friction = def.friction;
    Restitution = def.restitution;
    Density = def.density;
    Filter = {def.filter.categoryBits, def.filter.maskBits, def.filter.groupIndex};
    CustomColor = Color::FromHexa(def.customColor);
    IsSensor = def.isSensor;
    EnableSensorEvents = def.enableSensorEvents;
    EnableContactEvents = def.enableContactEvents;
    EnableHitEvents = def.enableHitEvents;
    EnablePreSolveEvents = def.enablePreSolveEvents;
    ForceContactCreation = def.forceContactCreation;
}

ShapeDef2D::operator b2ShapeDef() const
{
    b2ShapeDef def = b2DefaultShapeDef();

    def.friction = Friction;
    def.restitution = Restitution;
    def.density = Density;
    def.filter = {Filter.CategoryBits, Filter.MaskBits, Filter.GroupIndex};
    def.customColor = CustomColor.ToInt();
    def.isSensor = IsSensor;
    def.enableSensorEvents = EnableSensorEvents;
    def.enableContactEvents = EnableContactEvents;
    def.enableHitEvents = EnableHitEvents;
    def.enablePreSolveEvents = EnablePreSolveEvents;
    def.forceContactCreation = ForceContactCreation;

    return def;
}

} // namespace Lumen