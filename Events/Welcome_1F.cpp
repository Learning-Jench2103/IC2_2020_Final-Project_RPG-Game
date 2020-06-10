#include "Welcome_1F.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Welcome_1F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

void Welcome_1F::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Welcome_1F::Welcome_1F()
{
}

void Welcome_1F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "歡迎踏入成功牌EE系列高壓蒸氣鍋";
	Sleep(2000);
	setCursor(2, 3);
	cout << "這裡最強大而顯著的功效";
	Sleep(2000);
	setCursor(2, 5);
	cout << "就是訓練出在任何殘酷環境下";
	Sleep(2000);
	setCursor(2, 7);
	cout << "都能堅持不懈的毅力";
	Sleep(2000);
	setCursor(2, 9);
	cout << "面對各種惡劣險境的高EQ";
	Sleep(2000);
	setCursor(2, 11);
	cout << "和無人能敵的肝潛能應用能力";
	Sleep(5000);
	setCursor(2, 13);
	cout << "而首先你將進入的是由cpsoo先生執鞭的";
	Sleep(2000);
	setCursor(2, 15);
	cout << "從來沒人跟上車速的一樓GP教室";
	Sleep(3000);

	system("cls");
	Sleep(500);
	setCursor(2, 1);
	cout << "他是位優秀的學者";
	Sleep(2000);
	setCursor(2, 3);
	cout << "沉浸於自己的學術世界以科學為命";
	Sleep(2000);
	setCursor(2, 5);
	cout << "在GP教室中他養了隻野獸Goblin等著你";
	Sleep(2000);
	setCursor(2, 7);
	cout << "還有些不為人知的詭異機關";
	Sleep(2000);
	setCursor(2, 9);
	cout << "不時加上些奇怪要求讓一眾挑戰著叫苦連天";
	Sleep(2000);
	setCursor(2, 11);
	cout << "但沒有退路的你唯有殺出條血路";
	Sleep(2000);
	setCursor(2, 13);
	cout << "才能離開這個地方...";
	Sleep(2000);
	setCursor(2, 16);
	cout << "那麼，準備好的話，就";
	system("pause");

	system("cls");
	Sleep(500);
	setCursor(2, 1);
	cout << "cpsoo先生：歡迎！";
	Sleep(2000);
	setCursor(2, 3);
	cout << "cpsoo先生：Well ";
	Sleep(1000);
	cout << "剛剛無論你聽到些什麼都別理會";
	Sleep(2000);
	setCursor(2, 5);
	cout << "cpsoo先生：我人很好的你放心";
	Sleep(2000);
	setCursor(2, 7);
	cout << "cpsoo先生：請開心地不用顧慮我地玩!!";
	Sleep(6000);
	setCursor(2, 9);
	cout << "cpsoo先生：噢對了話說";
	Sleep(2000);
	setCursor(2, 11);
	cout << "cpsoo先生：我前幾天有份重要的筆記";
	Sleep(2000);
	setCursor(2, 13);
	cout << "cpsoo先生：在這兒被一陣怪風吹散一地";
	Sleep(2000);
	setCursor(2, 15);
	cout << "cpsoo先生：至少5張吧就你幫我找了";
	Sleep(2000);
	setCursor(2, 17);
	cout << "cpsoo先生：找不到你就";
	Sleep(5000);
	setCursor(2, 19);
	cout << "cpsoo先生：就別想離開了!!!!!";
	Sleep(2000);

}
