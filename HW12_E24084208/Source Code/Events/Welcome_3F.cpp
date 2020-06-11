#include "Welcome_3F.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Welcome_3F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

Welcome_3F::Welcome_3F()
{
}

void Welcome_3F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "JWMonster：厲害！";
	Sleep(2000);
	setCursor(2, 3);
	cout << "JWMonster：經過樓下的層層關卡";
	Sleep(2000);
	setCursor(2, 5);
	cout << "JWMonster：太高興在這裡看到你了";
	Sleep(2000);
	setCursor(2, 7);
	cout << "JWMonster：但是我這關";
	Sleep(2000);
	setCursor(2, 9);
	cout << "JWMonster：嘿嘿請加油";
	Sleep(2000);
	setCursor(2, 11);
	cout << "JWMonster：你放心真的很簡單的啦";
	Sleep(2000);
	setCursor(2, 13);
	cout << "JWMonster：只是要小心";
	Sleep(2000);
	setCursor(2, 15);
	cout << "JWMonster：小心路走一走掉下去";
	Sleep(2000);
	setCursor(2, 17);
	cout << "JWMonster：小心一陣風你就不見";
	Sleep(2000);
	setCursor(2, 19);
	cout << "JWMonster：小心一切可能的意外";
	Sleep(2000);
	setCursor(2, 21);
	cout << "JWMonster：或者必定的意外  就是我:D";
	Sleep(2000);
	setCursor(2, 23);
	cout << "JWMonster：那就出發囉GoGO";
	Sleep(3500);
}

