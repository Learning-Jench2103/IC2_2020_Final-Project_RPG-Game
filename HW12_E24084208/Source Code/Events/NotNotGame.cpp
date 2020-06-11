#include "NotNotGame.h"
#include "../Players/NovicePlayer.h"
#include <ctime>
#include <Windows.h>

void NotNotGame::initializeQuestion()
{
	ques_ans a;
	a.question = "左";
	a.answer.clear();
	a.answer.insert(75);
	source.push_back(a);

	a.question = "右";
	a.answer.clear();
	a.answer.insert(77);
	source.push_back(a);

	a.question = "上";
	a.answer.clear();
	a.answer.insert(72);
	source.push_back(a);

	a.question = "下";
	a.answer.clear();
	a.answer.insert(80);
	source.push_back(a);

	a.question = "非左";
	a.answer.clear();
	a.answer.insert(77);
	a.answer.insert(72);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "非右";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(72);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "非上";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(77);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "非下";
	a.answer.clear();
	a.answer.insert(77);
	a.answer.insert(72);
	a.answer.insert(75);
	source.push_back(a);

	a.question = "非非左";
	a.answer.clear();
	a.answer.insert(75);
	source.push_back(a);

	a.question = "非非右";
	a.answer.clear();
	a.answer.insert(77);
	source.push_back(a);

	a.question = "非非上";
	a.answer.clear();
	a.answer.insert(72);
	source.push_back(a);

	a.question = "非非下";
	a.answer.clear();
	a.answer.insert(80);
	source.push_back(a);

	a.question = "左 or 右";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(77);
	source.push_back(a);

	a.question = "上 or 下";
	a.answer.clear();
	a.answer.insert(72);
	a.answer.insert(80);
	source.push_back(a);

}

void NotNotGame::setCursor(int x, int y)
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

NotNotGame::NotNotGame(int num)
{
	question_num = num;
	initializeQuestion();
	said.resize(num / 5 - 1);
	for (int i = 0; i < said.size(); i++) {
		said.at(i) = false;
	}
}

bool NotNotGame::run(vector<NovicePlayer*> player_list)
{
	time_t begin;
	bool win = true;

	srand(time(NULL));
	for (int i = 0; i < question_num; i++) {
		system("cls");
		if (i % 5 == 0 && i != 0 && !said.at(i / 5 - 1)) {
			time_limit -= 0.2;
			Sleep(500);
			setCursor(2, 2);
			cout << "你很厲害！已經通過CAS先生 " << i << " 題的考驗";
			Sleep(2500);
			setCursor(2, 4);
			cout << "為了看出你真實的道行，CAS先生決定加快接下來答題的節奏";
			Sleep(2500);
			setCursor(2, 6);
			cout << "接下來的幾題，每題有 " << (double)time_limit << " 秒時間";
			Sleep(2500);
			setCursor(2, 8);
			cout << "相信你可以繼續完成挑戰的！！";
			said.at(i / 5 - 1) = true;
			Sleep(4000);
			setCursor(2, 10);
			cout << "Ready?? ";
			int temp = _getch();
			if (temp == 224) {
				temp = _getch();
			}
			Sleep(400);
			cout << "Go!";
			Sleep(1000);
			system("cls");
		}
		bool enter = false;
		int question_no = rand() % source.size();
		int response;
		cout << "\n     【邏輯大挑戰】\n     挑戰你的邏輯能力!!\n\n";
		cout << "                               時間限制：" << time_limit << " 秒\n";
		cout << "   題目：";
		cout << source.at(question_no).question << "\n\n";
		begin = clock();
		while (!enter) {
			if ((clock() - begin) / CLOCKS_PER_SEC >= time_limit) {
				response = -1;
				break;
			}
			if (!_kbhit()) {
				continue;
			}
			else {
				response = _getch();
				response = _getch();
				enter = true;
			}
		}
		if (source.at(question_no).answer.find(response) != source.at(question_no).answer.end()) {
			cout << "   恭喜答對！\n\n";
			cout << "   耗時 " << (clock() - (double)begin) / CLOCKS_PER_SEC << " 秒\n";
			Sleep(1000);
		}
		else if (revival_times > 0) {
			if (response == -1) {
				cout << "   超過時間惹衝啊啊";
			}
			else {
				cout << "   答錯了QQ\n";;
			}
			cout << "   您還有 " << revival_times << " 次復活機會！\n";
			--revival_times;
			--i;
			Sleep(2000);
			cout << "   休息一下，準備好再次迎接挑戰";	//接 system("pause"); 按任一鍵繼續
			system("pause");
			continue;
		}
		else {
			if (response == -1) {
				cout << "   超過時間惹QQ 下次請盡快哦";
			}
			else {
				cout << "   答錯了QQ 別氣餒歡迎再多逛逛廣場的角落 好課值得一修再修~~";;
			}
			win = false;
			system("pause");
			break;
		}
	}
	if (win) {
		system("cls");
		cout << "\n     恭喜你通過這項考驗!!\n\n     您隊伍中所有勇者將可獲得 15 點經驗值的獎勵~~\n\n     ";
		for (int i = 0; i < player_list.size(); i++) {
			player_list.at(i)->addExp(15);
		}
		system("pause");
	}
	system("cls");
	return win;
}

