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

	static float color[4] = { 1.f, 0.5f, 0.f, 1.f };
	c::accent = { color[0], color[1], color[2], 1.f };

	static int tabs = 0;

	ImGui::SetNextWindowSize(c::bg::size);
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
	{
		const ImVec2& pos = ImGui::GetWindowPos();
		const ImVec2& spacing = style->ItemSpacing;
		const ImVec2& region = ImGui::GetContentRegionMax();

		ImGui::GetBackgroundDrawList()->AddRectFilled(pos, pos + region, ImGui::GetColorU32(c::bg::background), c::bg::rounding);
		ImGui::GetBackgroundDrawList()->AddRectFilled(pos + spacing, pos + ImVec2(region.x - spacing.x, spacing.y + 45), ImGui::GetColorU32(c::child::background), c::child::rounding);
		ImGui::GetBackgroundDrawList()->AddRect(pos + spacing, pos + ImVec2(region.x - spacing.x, spacing.y + 45), ImGui::GetColorU32(c::child::outline), c::child::rounding);
		// I don't like this pattern =(
		// ImGui::GetBackgroundDrawList()->AddImage((void*)ASX, pos + spacing, pos + ImVec2(ASXw * 0.15f, ASXh * 0.15f));
		ImGui::GlowText(io.Fonts->Fonts[1], 30.f, "AimStar", pos + ImVec2(0, spacing.y + 10) + ImVec2(region.x / 3, 0), ImGui::GetColorU32(c::accent));
		
		ImGui::GetBackgroundDrawList()->AddRectFilled(pos + spacing + ImVec2(0,60), pos + ImVec2(region.x - spacing.x, 140), ImGui::GetColorU32(c::child::background), c::child::rounding);
		ImGui::GetBackgroundDrawList()->AddRect(pos + spacing + ImVec2(0, 60), pos + ImVec2(region.x - spacing.x, 140), ImGui::GetColorU32(c::child::outline), c::child::rounding);
	
		ImGui::GetBackgroundDrawList()->AddRectFilled(pos + spacing + ImVec2(0, 137), pos + region - spacing, ImGui::GetColorU32(c::child::background), c::child::rounding);
		ImGui::GetBackgroundDrawList()->AddRect(pos + spacing + ImVec2(0, 137), pos + region - spacing, ImGui::GetColorU32(c::child::outline), c::child::rounding);
	
		ImGui::SetCursorPos(ImVec2(spacing.x, spacing.y + 60));
		ImGui::BeginGroup();
		{
			if (ImGui::SubTab(0 == tabs, "ESP", ImVec2(60, 60))) tabs = 0;
			ImGui::SameLine(0, 5);
			if (ImGui::SubTab(1 == tabs, "Aim", ImVec2(60, 60))) tabs = 1;
			ImGui::SameLine(0, 5);
			if (ImGui::SubTab(2 == tabs, "Misc", ImVec2(65, 60))) tabs = 2;
			ImGui::SameLine(0, 5);
			if (ImGui::SubTab(3 == tabs, "Config", ImVec2(75, 60))) tabs = 3;
		}
		ImGui::EndGroup();
	}
}