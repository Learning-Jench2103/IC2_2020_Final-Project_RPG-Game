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

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
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
			cout << "��";
		}
		setColor();
	}

	Sleep(500);
	setCursor(4, 26);
	cout << "���ߧA�����@�����i�઺���ȡG";
	Sleep(2000);
	setCursor(4, 28);
	cout << "�q�LJWMonster�}�x������";
	Sleep(2000);
	setCursor(4, 30);
	cout << "�]���Q�׹L�@���W�|�񪺦M��";
	Sleep(2000);
	setCursor(4, 32);
	cout << "�n�W�o���ʨ��̬����Ť���a";
	Sleep(2000);
	setCursor(4, 34);
	cout << "�ڭ̦��t�A�|�I";
	setCursor(4, 36);
	system("pause");

}
