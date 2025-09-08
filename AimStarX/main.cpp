#include <iostream>
#include <filesystem>
#include <string>
#include <chrono>
#include <iomanip>
#include <ShlObj.h>
#include <stdio.h>

using namespace std;

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

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	cout << "Press [DEL] to show or hide menu." << endl;
	cout << "ENjoy! <3" << endl;
}

void Exit()
{
	system("pause");
	exit(0);
}

int main(void)
{
	cheat();
	Exit();
}