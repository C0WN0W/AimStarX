#include "Menu.hpp"
#include "Images/Images.hpp"
#include <iostream>

ID3D11ShaderResourceView* ASX = NULL;
int ASXw = 0, ASXh = 0;

void LoadImages()
{
	if (ASX == NULL)
	{
		Gui.LoadTextureFromMemory(Image::ASX, sizeof Image::ASX, &ASX, &ASXw, &ASXh);
	}
}

void GUI::DrawCallBack() noexcept
{
	LoadImages();
	ImGuiIO& io = ImGui::GetIO();
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
		ImGui::GetBackgroundDrawList()->AddRectFilled(pos + spacing, pos + ImVec2(region.x - spacing.x, spacing.y + 45), ImGui::GetColorU32(c::child::background), c::bg::rounding);
		// I don't like this pattern =(
		// ImGui::GetBackgroundDrawList()->AddImage((void*)ASX, pos + spacing, pos + ImVec2(ASXw * 0.15f, ASXh * 0.15f));
		ImGui::GlowText(io.Fonts->Fonts[1], 30.f, "AimStar", pos + ImVec2(0, spacing.y + 10) + ImVec2(region.x / 3, 0), ImColor(255, 0, 0, 255));
	}
}