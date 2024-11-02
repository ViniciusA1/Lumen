#include "Lumen/Editor/Panel/ConsolePanel.hpp"
#include "Lumen/Core/Log.hpp"
#include "imgui.h"

namespace Lumen
{

void ConsolePanel::Draw()
{
    ImGui::Begin("Console");

    ImGui::Text("Filter:");
    ImGui::SameLine();
    ImGui::InputText("##Filter", m_FilterBuffer.data(), m_FilterBuffer.size());
    ImGui::SameLine();
    if (ImGui::Button("Clear"))
    {
        Log::Clear();
    }
    ImGui::Separator();

    ImGui::BeginChild("LogArea", ImVec2(0, 0), false,
                      ImGuiWindowFlags_HorizontalScrollbar);
    for (const auto &log : Log::GetLogs())
    {
        if (m_FilterBuffer[0] != '\0' &&
            log.Message.find(m_FilterBuffer.data()) == std::string::npos)
        {
            continue;
        }

        ImVec4 color;
        switch (log.Level)
        {
        case LogLevel::Info:
            color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
            break;
        case LogLevel::Warning:
            color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case LogLevel::Error:
            color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
            break;
        }

        ImGui::PushStyleColor(ImGuiCol_Text, color);
        ImGui::TextWrapped("%s", log.Message.c_str());
        ImGui::PopStyleColor();
    }

    if (m_ScrollToBottom)
        ImGui::SetScrollHereY(1.0f);
    m_ScrollToBottom = false;

    ImGui::EndChild();
    ImGui::End();
}

} // namespace Lumen