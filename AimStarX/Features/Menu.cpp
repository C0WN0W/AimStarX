#include "Menu.hpp"

void GUI::DrawCallBack() noexcept
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(0, 0);
	style->WindowBorderSize = 0;
	style->ItemSpacing = ImVec2(20, 20);
	style->ScrollbarSize = 8.f;

	static float color[4] = { 0.f, 1.f, 0.f, 1.f };
	c::accent = { color[0], color[1], color[2], 1.f };

	ImGui::SetNextWindowSize(c::bg::size);
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
	{
		const ImVec2& pos = ImGui::GetWindowPos();
		const ImVec2& spacing = style->ItemSpacing;
		const ImVec2& region = ImGui::GetContentRegionMax();

		ImGui::GetBackgroundDrawList()->AddRectFilled(pos, pos + region, ImGui::GetColorU32(c::bg::background), c::bg::rounding);

	}
}