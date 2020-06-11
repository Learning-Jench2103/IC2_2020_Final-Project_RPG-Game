#include "NotNotGame.h"
#include "../Players/NovicePlayer.h"
#include <ctime>
#include <Windows.h>

void NotNotGame::initializeQuestion()
{
	ques_ans a;
	a.question = "��";
	a.answer.clear();
	a.answer.insert(75);
	source.push_back(a);

	a.question = "�k";
	a.answer.clear();
	a.answer.insert(77);
	source.push_back(a);

	a.question = "�W";
	a.answer.clear();
	a.answer.insert(72);
	source.push_back(a);

	a.question = "�U";
	a.answer.clear();
	a.answer.insert(80);
	source.push_back(a);

	a.question = "�D��";
	a.answer.clear();
	a.answer.insert(77);
	a.answer.insert(72);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "�D�k";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(72);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "�D�W";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(77);
	a.answer.insert(80);
	source.push_back(a);

	a.question = "�D�U";
	a.answer.clear();
	a.answer.insert(77);
	a.answer.insert(72);
	a.answer.insert(75);
	source.push_back(a);

	a.question = "�D�D��";
	a.answer.clear();
	a.answer.insert(75);
	source.push_back(a);

	a.question = "�D�D�k";
	a.answer.clear();
	a.answer.insert(77);
	source.push_back(a);

	a.question = "�D�D�W";
	a.answer.clear();
	a.answer.insert(72);
	source.push_back(a);

	a.question = "�D�D�U";
	a.answer.clear();
	a.answer.insert(80);
	source.push_back(a);

	a.question = "�� or �k";
	a.answer.clear();
	a.answer.insert(75);
	a.answer.insert(77);
	source.push_back(a);

	a.question = "�W or �U";
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

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
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
			cout << "�A�ܼF�`�I�w�g�q�LCAS���� " << i << " �D������";
			Sleep(2500);
			setCursor(2, 4);
			cout << "���F�ݥX�A�u�ꪺ�D��ACAS���ͨM�w�[�ֱ��U�ӵ��D���`��";
			Sleep(2500);
			setCursor(2, 6);
			cout << "���U�Ӫ��X�D�A�C�D�� " << (double)time_limit << " ��ɶ�";
			Sleep(2500);
			setCursor(2, 8);
			cout << "�۫H�A�i�H�~�򧹦��D�Ԫ��I�I";
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
		cout << "\n     �i�޿�j�D�ԡj\n     �D�ԧA���޿��O!!\n\n";
		cout << "                               �ɶ�����G" << time_limit << " ��\n";
		cout << "   �D�ءG";
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
			cout << "   ���ߵ���I\n\n";
			cout << "   �Ӯ� " << (clock() - (double)begin) / CLOCKS_PER_SEC << " ��\n";
			Sleep(1000);
		}
		else if (revival_times > 0) {
			if (response == -1) {
				cout << "   �W�L�ɶ��S�İڰ�";
			}
			else {
				cout << "   �����FQQ\n";;
			}
			cout << "   �z�٦� " << revival_times << " ���_�����|�I\n";
			--revival_times;
			--i;
			Sleep(2000);
			cout << "   �𮧤@�U�A�ǳƦn�A���ﱵ�D��";	//�� system("pause"); �����@���~��
			system("pause");
			continue;
		}
		else {
			if (response == -1) {
				cout << "   �W�L�ɶ��SQQ �U���кɧ֮@";
			}
			else {
				cout << "   �����FQQ �O��k�w��A�h�}�}�s�������� �n�ҭȱo�@�צA��~~";;
			}
			win = false;
			system("pause");
			break;
		}
	}
	if (win) {
		system("cls");
		cout << "\n     ���ߧA�q�L�o������!!\n\n     �z����Ҧ��i�̱N�i��o 15 �I�g��Ȫ����y~~\n\n     ";
		for (int i = 0; i < player_list.size(); i++) {
			player_list.at(i)->addExp(15);
		}
		system("pause");
	}
	system("cls");
	return win;
}

