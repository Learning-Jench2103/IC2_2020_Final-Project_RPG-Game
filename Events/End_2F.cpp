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

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
	SetConsoleCursorPosition(hin, pos);
}

End_2F::End_2F()
{
}

void End_2F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "���ߡI";
	Sleep(2000);
	setCursor(2, 3);
	cout << "�u�����b�o�̬ݨ�A";
	Sleep(2000);
	setCursor(2, 5);
	cout << "�򱵵ۥu�n�q�LCAS���ͪ������D��";
	Sleep(2000);
	setCursor(2, 7);
	cout << "�L���U���Y�줣���W���~";
	Sleep(2000);
	setCursor(2, 9);
	cout << "�A�N�i�H�e���U�ӥت��a�o";
	Sleep(2000);
	setCursor(2, 11);
	cout << "�ǳƦn�F�ܡI";
	system("pause");
}
