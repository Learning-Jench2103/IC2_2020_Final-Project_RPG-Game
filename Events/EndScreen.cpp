#include "EndScreen.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

void EndScreen::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

void EndScreen::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

EndScreen::EndScreen()
{
	for (int i = 0; i < 23; i++) {
		setCursor(2, 1 + i);
		for (int j = 0; j < 42; j++) {
			setColor(color[i][j]);
			cout << "■";
		}
		setColor();
	}

	Sleep(500);
	setCursor(4, 26);
	cout << "恭喜你完成一項不可能的任務：";
	Sleep(2000);
	setCursor(4, 28);
	cout << "通過JWMonster艱困的考驗";
	Sleep(2000);
	setCursor(4, 30);
	cout << "也順利度過一路上四伏的危機";
	Sleep(2000);
	setCursor(4, 32);
	cout << "登上這方圓百里最美的空中綠地";
	Sleep(2000);
	setCursor(4, 34);
	cout << "我們有緣再會！";
	setCursor(4, 36);
	system("pause");

}
