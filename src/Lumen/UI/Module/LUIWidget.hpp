#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Asset/AssetType.hpp"
#include "Lumen/Core/Action.hpp"
#include "Lumen/Graphics/Color.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/UI/Module/LUIStructures.hpp"

#include <span>
#include <string>
#include <vector>

namespace Lumen::LUI
{

struct ThumbnailAssetData
{
    Texture2D Texture;
    std::string Name;
    std::string Description;
    Vector2 Size;
    Action OnClick;
};

struct ThumbnailIconData
{
    std::string Icon;
    std::string Name;
    Vector2 Size;
    Action OnClick;
};

} // namespace Lumen::LUI

namespace Lumen::LUI
{

void BeginDisabled(bool disabled = true);
void EndDisabled();

void BeginGroup();
void EndGroup();

void NewLine();
void SameLine(float offsetX = 0.0f, float spacing = -1.0f);
void Separator();
void Spacing();

void SetNextItemWidth(float width);
void SetTooltip(const std::string &text);

bool Button(const std::string &label, const Vector2 &size = Vector2(0, 0),
            bool showBg = true);
bool ButtonInvisible(const std::string &label, const Vector2 &size = Vector2(0, 0));
bool ButtonPopup();
bool ButtonToggle(const std::string &label, bool &value,
                  const Vector2 &size = Vector2(0, 0),
                  const std::string &toggledLabel = "");
// bool ButtonSwitch(const std::string &label, bool &value);

bool Checkbox(const std::string &label, bool *value);

bool ColorEdit(const std::string &label, Color &color,
               ColorEditFlags flags = ColorEditFlags::None);

bool Combo(const std::string &label, const std::vector<std::string> &items,
           std::string &currentItem);
bool Combo(const std::string &label, const std::vector<std::string> &items,
           int &currentItem);

void DragFloat(const std::string &label, float *value, float speed = 1.0f,
               float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
               SliderFlags flags = SliderFlags::None);
void DragFloat2(const std::string &label, float *value, float speed = 1.0f,
                float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
                SliderFlags flags = SliderFlags::None);
void DragFloat3(const std::string &label, float *value, float speed = 1.0f,
                float min = 0.0f, float max = 0.0f, const std::string &format = "%.3f",
                SliderFlags flags = SliderFlags::None);

void DragVec2(const std::string &label, Vector2 &vec, float speed = 1.0f,
              float min = 0.0f, float max = 0.0f, const Vector2 &reset = {},
              const std::string &format = "%.3f", SliderFlags flags = SliderFlags::None);
void DragVec3(const std::string &label, Vector3 &vec, float speed = 1.0f,
              float min = 0.0f, float max = 0.0f, const Vector3 &reset = {},
              const std::string &format = "%.3f", SliderFlags flags = SliderFlags::None);
void DragVec4(const std::string &label, Vector4 &vec, float speed = 1.0f,
              float min = 0.0f, float max = 0.0f, const Vector4 &reset = {},
              const std::string &format = "%.3f", SliderFlags flags = SliderFlags::None);

bool Filter(const std::vector<std::string> &filters, int &currentFilter);
bool FilterButton(const std::vector<std::string> &filters, int &currentFilter);

void Image(const Texture2D &texture, const Vector2 &size,
           const Vector2 &uv0 = Vector2(0, 0), const Vector2 &uv1 = Vector2(1, 1),
           Color tintColor = Color::White, Color borderColor = Color(0, 0, 0, 0));

void Image(const Texture2D &texture, float scale = 1.0f,
           const Vector2 &uv0 = Vector2(0, 0), const Vector2 &uv1 = Vector2(1, 1),
           Color tintColor = Color::White, Color borderColor = Color(0, 0, 0, 0));

bool InputText(const std::string &label, const std::span<char> &buffer,
               bool expand = false);
bool InputTextWithHint(const std::string &label, const std::string &hint,
                       const std::span<char> &buffer, bool expand = false);

void ObjectField(const std::string &label, AssetHandle &asset, AssetType type,
                 const Action &onSearch);

void SearchBar(const std::span<char> &buffer, bool expand = false);

bool Selectable(const std::string &label, bool selected = false,
                SelectableFlags flags = SelectableFlags::None,
                const Vector2 &size = {0, 0});

bool SliderFloat(const std::string &label, float *value, float min, float max);

bool ThumbnailAsset(const Texture2D &texture, const std::string &name,
                    const std::string &description, const Vector2 &size,
                    const Vector4 &uv = {0, 0, 1, 1}, bool selected = false);
bool ThumbnailAsset(const ThumbnailAssetData &thumbnail, const Vector4 &uv = {0, 0, 1, 1},
                    bool selected = false);
bool ThumbnailIcon(const std::string &icon, const std::string &name, const Vector2 &size,
                   bool selected = false);
bool ThumbnailIcon(const ThumbnailIconData &thumbnail, bool selected = false);

} // namespace Lumen::LUI