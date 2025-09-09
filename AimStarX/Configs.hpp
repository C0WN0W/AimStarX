#pragma once
#include "OS-ImGui/OS-ImGui.h"

namespace Configs
{
	namespace ESP
	{
		inline bool Enable = false;
		inline bool Box = true;
		inline bool Line = false;

		inline float BoxCol[4] = { 1.f, 1.f, 1.f, 1.f };
		inline float LineCol[4] = { 1.f, 1.f, 1.f, 1.f };
	}
}