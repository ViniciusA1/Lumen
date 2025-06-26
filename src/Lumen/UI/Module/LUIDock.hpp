#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

enum class Direction
{
    None = -1,
    Left = 0,
    Right = 1,
    Up = 2,
    Down = 3,
    COUNT
};

} // namespace Lumen::LUI

namespace Lumen::LUI
{

using ID = unsigned int;

void DockSpace(ID id, const Vector2 &size = {0, 0},
               DockNodeFlags flags = DockNodeFlags::None);

void DockSpaceOverViewport(ID id = 0, DockNodeFlags flags = DockNodeFlags::None);

void DockBuilderRemoveNode(ID nodeID);
void DockBuilderAddNode(ID nodeID, DockNodeFlags flags = DockNodeFlags::None);
void DockBuilderSetNodeSize(ID nodeID, const Vector2 &size);
ID DockBuilderSplitNode(ID nodeID, Direction splitDir, float sizeRatioForNodeAtDir,
                        ID *outIDAtDir = nullptr, ID *outIDAtOppositeDir = nullptr);
void DockBuilderDockWindow(const std::string &windowName, ID nodeID);
void DockBuilderFinish(ID nodeID);

} // namespace Lumen::LUI