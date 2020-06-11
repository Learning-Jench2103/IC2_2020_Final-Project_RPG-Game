#include "legend_3F.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void legend_3F::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void legend_3F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

legend_3F::legend_3F()
{
}

void legend_3F::display()
{
	setCursor(2, 1);
	cout << "【 3F ICCPP World 圖例 】";
	setCursor(1, 4); setColor(249); cout << "■"; setColor(); cout << "  商店街";
	setCursor(1, 6); setColor(165); cout << "●"; setColor(); cout << "  密道 - 猜猜哪個是對的^^";
	setCursor(1, 8); setColor(206); cout << "■"; setColor(); cout << "  通往終點的路 - 請先活著打敗JWMonster!";
	setCursor(1, 10); setColor(252); cout << "■"; setColor(); cout << "  電梯下樓 - 返回LSD廣場";
	setCursor(1, 12); cout << "請按任意鍵返回~~";
	if (_getch() == 224) {
		_getch();
		return;
	}
}
