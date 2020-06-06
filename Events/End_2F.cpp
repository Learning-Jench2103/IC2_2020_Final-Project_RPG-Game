#include "End_2F.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void End_2F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

End_2F::End_2F()
{
}

void End_2F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "恭喜！";
	Sleep(2000);
	setCursor(2, 3);
	cout << "真高興在這裡看到你";
	Sleep(2000);
	setCursor(2, 5);
	cout << "緊接著只要通過CAS先生的期末挑戰";
	Sleep(2000);
	setCursor(2, 7);
	cout << "他麾下的某位不知名野獸";
	Sleep(2000);
	setCursor(2, 9);
	cout << "你就可以前往下個目的地囉";
	Sleep(2000);
	setCursor(2, 11);
	cout << "準備好了嗎！";
	system("pause");
}
