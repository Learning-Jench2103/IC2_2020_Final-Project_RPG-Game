#include "Welcome_2F.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Welcome_2F::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

Welcome_2F::Welcome_2F()
{
}

void Welcome_2F::run()
{
	Sleep(500);
	setCursor(2, 1);
	cout << "真了不起！";
	Sleep(2500);
	setCursor(2, 3);
	cout << "竟然順利通過了cpsoo先生的考驗";
	Sleep(2500);
	setCursor(2, 5);
	cout << "接下來你將進入EE高壓鍋的下一個烹調階段";
	Sleep(2500);
	setCursor(2, 7);
	cout << "進入由CAS先生執掌的LSD廣場";
	Sleep(2500);
	setCursor(2, 9);
	cout << "他擁有讓人跟他一起充滿活力的魔法";
	Sleep(2500);
	setCursor(2, 11);
	cout << "是個超級大好人呢";
	Sleep(2500);
	setCursor(2, 13);
	cout << "像是在這張地圖上";
	Sleep(2500);
	setCursor(2, 15);
	cout << "CAS先生為了減輕你的路途辛勞";
	Sleep(2500);
	setCursor(2, 17);
	cout << "特地在某些路口幫你留了點提示";
	Sleep(2500);
	setCursor(2, 19);
	cout << "不過這也是有點代價的啦啦";
	Sleep(2500);
	setCursor(2, 21);
	cout << "要是在這些路口還是走錯了";
	Sleep(2000);
	cout << " 就得接受一點點懲罰囉";
	
	Sleep(4000);
	system("cls");
	Sleep(500);
	setCursor(2, 1);
	cout << "在這座廣場中他也精心為你設計了些";
	Sleep(2500);
	setCursor(2, 3);
	cout << "精彩又刺激的挑戰";
	Sleep(2500);
	setCursor(2, 5);
	cout << "唯一要注意的是";
	Sleep(2500);
	setCursor(2, 7);
	cout << "請確保你的腦筋";
	Sleep(2500);
	setCursor(2, 9);
	cout << "在持續高速運轉狀態下";
	Sleep(2500);
	setCursor(2, 11);
	cout << "別過熱當機了:)";
	Sleep(2500);
	setCursor(2, 14);
	cout << "準備好";
	system("pause");
}