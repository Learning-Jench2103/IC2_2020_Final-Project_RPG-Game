#include "legend_1F.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void legend_1F::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void legend_1F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

legend_1F::legend_1F()
{
}

void legend_1F::display()
{
	setCursor(2, 1);
	cout << "【 1F GP教室 圖例 】";
	setCursor(1, 4); setColor(249); cout << "■"; setColor(); cout << "  商店街";
	setCursor(1, 6); setColor(253); cout << "■"; setColor(); cout << "  GoblinMonster的窩";
	setCursor(1, 8); setColor(206); cout << "■"; setColor(); cout << "  電梯上樓 - 前往LSD廣場";
	setCursor(1, 10); cout << "請按任意鍵返回~~";
	if (_getch() == 224) {
		_getch();
		return;
	}
}
