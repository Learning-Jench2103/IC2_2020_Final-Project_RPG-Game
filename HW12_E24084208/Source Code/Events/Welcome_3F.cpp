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

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
	SetConsoleCursorPosition(hin, pos);
}

Welcome_3F::Welcome_3F()
{
}

void Welcome_3F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "JWMonster�G�F�`�I";
	Sleep(2000);
	setCursor(2, 3);
	cout << "JWMonster�G�g�L�ӤU���h�h���d";
	Sleep(2000);
	setCursor(2, 5);
	cout << "JWMonster�G�Ӱ����b�o�̬ݨ�A�F";
	Sleep(2000);
	setCursor(2, 7);
	cout << "JWMonster�G���O�ڳo��";
	Sleep(2000);
	setCursor(2, 9);
	cout << "JWMonster�G�K�K�Х[�o";
	Sleep(2000);
	setCursor(2, 11);
	cout << "JWMonster�G�A��߯u����²�檺��";
	Sleep(2000);
	setCursor(2, 13);
	cout << "JWMonster�G�u�O�n�p��";
	Sleep(2000);
	setCursor(2, 15);
	cout << "JWMonster�G�p�߸����@�����U�h";
	Sleep(2000);
	setCursor(2, 17);
	cout << "JWMonster�G�p�ߤ@�}���A�N����";
	Sleep(2000);
	setCursor(2, 19);
	cout << "JWMonster�G�p�ߤ@���i�઺�N�~";
	Sleep(2000);
	setCursor(2, 21);
	cout << "JWMonster�G�Ϊ̥��w���N�~  �N�O��:D";
	Sleep(2000);
	setCursor(2, 23);
	cout << "JWMonster�G���N�X�o�oGoGO";
	Sleep(3500);
}

