#pragma once
#include "OS-ImGui_Base.h"

namespace OSImGui
{
#ifndef OSIMGUI_INTERNAL

	class OSImGui_External : public OSImGui_Base
	{
	private:
		// ��������
		WindowType Type = NEW;
	public:
		// ����һ���´���
		void NewWindow(std::string WindowName, Vec2 WindowSize, std::function<void()> CallBack, bool Transparent = false);
		// ���ӵ���һ��������
		void AttachAnotherWindow(std::string DestWindowName, std::string DestWindowClassName, std::function<void()> CallBack);
	private:
		void MainLoop();
		bool UpdateWindowData();
		bool CreateMyWindow();
		bool PeekEndMessage();
	};

#endif
}