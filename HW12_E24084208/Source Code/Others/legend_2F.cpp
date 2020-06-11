#include "legend_2F.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void legend_2F::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void legend_2F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

legend_2F::legend_2F()
{
}

void legend_2F::display()
{
	setCursor(2, 1);
	cout << "【 2F LSD廣場 圖例 】";  
	setCursor(1, 4); setColor(249); cout << "■"; setColor(); cout << "  商店街";
	setCursor(1, 6); setColor(206); cout << "■"; setColor(); cout << "  電梯上樓 - Zombie等著你";
	setCursor(1, 8); setColor(156); cout << "★"; setColor(); cout << "  CAS先生的祕密任務";
	setCursor(1, 10); setColor(252); cout << "■"; setColor(); cout << "  電梯下樓 - 往GP教室";
	setCursor(1, 12); cout << "請按任意鍵返回~~";
	if (_getch()==224) {
		_getch();
		return;
	}
}
