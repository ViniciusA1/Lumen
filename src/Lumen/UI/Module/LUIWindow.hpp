#pragma once

#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

bool Begin(const std::string &name, bool *p_open = nullptr,
           WindowFlags flags = WindowFlags::None);
void End();

bool BeginChild(const std::string &label, const Vector2 &size = {0, 0},
                ChildFlags childFlags = ChildFlags::None,
                WindowFlags windowFlags = WindowFlags::None);
void EndChild();

void Centralize(CondFlags cond = CondFlags::None);

Vector2 GetContentRegionAvail();
Vector2 GetViewportCenter();
Vector2 GetWindowContentRegionMax();
float GetWindowHeight();
Vector2 GetWindowPos();
float GetWindowWidth();

void SetNextWindowPos(const Vector2 &pos, CondFlags cond = CondFlags::None,
                      const Vector2 &pivot = {0, 0});
void SetNextWindowSize(const Vector2 &size, CondFlags cond = CondFlags::None);

} // namespace Lumen::LUI