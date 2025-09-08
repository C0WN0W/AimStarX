#include <iostream>
#include <filesystem>
#include <string>
#include <chrono>
#include <iomanip>
#include <ShlObj.h>
#include <stdio.h>
#include "Utils/ProcessManager.hpp"
#include "Cheats.hpp"

using namespace std;

void Exit()
{
	system("pause");
	exit(0);
}

void cheat()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	cout << R"(                                                                   
	    ___    _          _____ __            _  __
	   /   |  (_)___ ___ / ___// /_____ _____| |/ /
	  / /| | / / __ `__ \\__ \/ __/ __ `/ ___/   / 
	 / ___ |/ / / / / / /__/ / /_/ /_/ / /  /   |  
	/_/  |_/_/_/ /_/ /_/____/\__/\__,_/_/  /_/|_|  
	)" << endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");
	switch (ProcessStatus) {
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "Please run the game at first!\n";
		Exit();
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "Please run as Administrator!\n";
		Exit();
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "Cannot get the module address!\n";
		Exit();
	}

	cout << "Press [DEL] to show or hide menu." << endl;

	try
	{
		Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", Cheats::Run);
	}
	catch (OSImGui::OSException& e)
	{
		try
		{
			// Perfect World version
			Gui.AttachAnotherWindow("\u53cd\u6050\u7cbe\u82f1\uff1a\u5168\u7403\u653b\u52bf", "SDL_app", Cheats::Run);
		}
		catch (OSImGui::OSException& e)
		{
			cout << e.what() << endl;
		}
	}
}

int main(void)
{
	cheat();
}