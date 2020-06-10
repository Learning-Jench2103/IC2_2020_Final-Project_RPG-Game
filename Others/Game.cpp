#include "Game.h"
#include <conio.h>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;

void Game::generatePlayers()
{
	Menu player_select_menu;
	{
		player_select_menu.question_name = "�п�ܤ@�Ө���";

		player_select_menu.instruction.push_back("�z�i�H�u�֦��@�Ө���A�åH�L�Ƶ��s��");
		player_select_menu.instruction.push_back("�z�]�i�H�֦��ѼƭӦ����զ����Զ��A�éM�L�̤@�P���Q�ѤU");
		player_select_menu.instruction.push_back("");
		player_select_menu.instruction.push_back("�H�U�O�i��ܪ�����M��ΥL�̤��O���ݩ�");
		player_select_menu.instruction.push_back("�ХH������� Enter ��̷ܳQ�n��¾�~");
		player_select_menu.instruction.push_back("��ܧ����Ы� Esc �h�X���");

		player_select_menu.options.push_back(" NovicePlayer ");
		player_select_menu.options.push_back("  OrcPlayer   ");
		player_select_menu.options.push_back(" KnightPlayer ");
		player_select_menu.options.push_back("MagicianPlayer");

		player_select_menu.option_descriptions.push_back("�S���L�h�S��ޯ������L���¡F�¯u���S������⩹����L���H���ߡA�Ө�����֪�����");
		player_select_menu.option_descriptions.push_back("�� NovicePlayer �֦���j������O�A�o�]�����̷N�Ѩ�L���F�`�A�U�⺥�����d����");
		player_select_menu.option_descriptions.push_back("�֦��N�]�O�ഫ����q���S��ޯ�A�����b�d�v�@�v���ک����঳��L�I�樭");
		player_select_menu.option_descriptions.push_back("�ϥίS�ޥi�N��q�ର�]�O�A��b����W���ɪ���������j�O���P�R�@��");
	}

	int response;
	bool at_least_one = false;
	do {
		NovicePlayer* player_ptr;
		system("cls");
		response = player_select_menu.run();
		switch (response) {
		case 0:
			player_ptr = new NovicePlayer;
			break;
		case 1:
			player_ptr = new OrcPlayer;
			break;
		case 2:
			player_ptr = new KnightPlayer;
			break;
		case 3:
			player_ptr = new MagicianPlayer;
			break;
		default:
			player_ptr = new NovicePlayer;
		}
		if (response != -1) {
			cout << "     ���L���ӦW�r�a�G";
			string input;
			getline(cin, input);
			player_ptr->setName(input);
			player_list.push_back(player_ptr);
			at_least_one = true;
		}
		else if (!at_least_one) {
			cout << "     �z������ܤֻݭn�@��¾�~�@�@�@";
			Sleep(1000);
			system("cls");
			Sleep(500);
		}
	} while (response != -1 || !at_least_one);

	all_player_level_sigma = player_list.size();
}

void Game::initializeFirstFloor()
{
	if (First_floor != nullptr) {
		delete First_floor;
	}
	First_floor = new Field("1F GP�Ы�.csv", 14, 14);
	First_floor->setGrid(111, "����", "��", 253, "");
	First_floor->setGrid(131, "�ȱ�", "��", 250, "");
	First_floor->setGrid(121, "�ά}", "��", 250, "");
	First_floor->setGrid(11, "�ө�", "��", 249, "");
	First_floor->setGrid(101, "", "��", 206, "");
}

void Game::initializeSecondFloor()
{
	if (Second_floor != nullptr) {
		delete Second_floor;
	}
	Second_floor = new Field("2F LSD�s��.csv", 14, 14);
	Second_floor->setGrid(11, "�ө�", "��", 249, "");
	Second_floor->setGrid(201, "", "��", 206, "");
	Second_floor->setGrid(221, "", "��", 242, "Q�G�̰��Ѫ����G");
	Second_floor->setGrid(222, "", "��", 242, "Q�G���O�̮t�����G");
	Second_floor->setGrid(223, "", "��", 242, "Q�G���}�y�L�� �j­�J�}�� �u���g�Y����s �@�n�R�E���F��");
	Second_floor->setGrid(224, "", "��", 242, "Q�G�I�O�L�� �����峹");
	Second_floor->setGrid(231, "", "�h", 165, "");
	Second_floor->setGrid(232, "", "��", 165, "");
	Second_floor->setGrid(233, "", "��", 165, "");
	Second_floor->setGrid(234, "", "�l", 165, "");
	Second_floor->setGrid(235, "", "��", 165, "");
	Second_floor->setGrid(236, "", "��", 165, "");
	Second_floor->setGrid(237, "", "�~", 165, "");
	Second_floor->setGrid(238, "", "�G", 165, "");
	Second_floor->setGrid(239, "", "��", 165, "");
	Second_floor->setGrid(240, "", "��", 165, "");
	Second_floor->setGrid(241, "", "�A", 165, "");
	Second_floor->setGrid(242, "", "�l", 165, "");
	Second_floor->setGrid(243, "", "��", 165, "");
	Second_floor->setGrid(244, "", "��", 165, "");
	Second_floor->setGrid(245, "", "�Q", 165, "");
	Second_floor->setGrid(246, "", "��", 165, "");
	Second_floor->setGrid(247, "", "��", 165, "");
	Second_floor->setGrid(248, "", "��", 165, "");
	Second_floor->setGrid(261, "NotNot", "��", 156, "");
	Second_floor->setGrid(262, "NotNot", "��", 156, "");
	Second_floor->setGrid(271, "", "��", 250, "");
}

void Game::initializeThirdFloor()
{
	if (Third_floor != nullptr) {
		delete Third_floor;
	}
	Third_floor = new Field("3F ICCPP World.csv", 15, 11);
	Third_floor->setGrid(11, "�ө�", "��", 249, "");
	Third_floor->setGrid(301, "", "��", 206, "");
	Third_floor->setGrid(311, "", "��", 165, "");
	Third_floor->setGrid(312, "", "��", 165, "");
	Third_floor->setGrid(313, "", "��", 165, "");
	Third_floor->setGrid(314, "", "��", 165, "");
	Third_floor->setGrid(315, "", "��", 165, "");
}

void Game::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
	SetConsoleCursorPosition(hin, pos);
}

void Game::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

bool Game::play()
{
	int press;
	bool game_end = false;

	while (!game_end) {
		system("cls");
		current_field->display();

		if (current_field == First_floor) {
			cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
		}

		// random gift begin
		{
			setColor(12);
			if (step_count > 30 && rand() % 40 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addExp(10);
				}
				cout << "  ���߽���_�c�I�A���C�즨������o�F10�I�g��ȡI\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 30 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addHp(5);
				}
				cout << "  ���߽���_�c�I�A���C�즨������o�F5�I��q�I\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 26 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addExp(5);
				}
				cout << "  ���߽���_�c�I�A���C�즨������o�F5�I�g��ȡI\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 22 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					money += 10;
				}
				cout << "  ���߽���_�c�I�A��o�F10�������I\n\n  ";
				setColor();
				step_count = 0;
			}
			setColor();
		}
		// random gift end

		// detect current_symbol before moving
		set<int> choose_member;

		int current_symbol = current_field->getSymbol();
		{
			// All map
			switch (current_symbol) {
			case 11:
			{
				system("cls");
				store->run();
				system("cls");
				current_field->display();
				if (current_field == First_floor) {
					cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
				}
			}
			break;
			case 21:
			{
				if (rand() % 100 == 0) {
					system("cls");
					cout << "  ���߱z�b�o�Ӥ��_��������\n";	Sleep(1000);
					cout << "  �J�W�F�d�~�@�J��\n";	Sleep(1000);
					cout << "  cpsoo���ͨ���������\n";	Sleep(1000);
					cout << "  �C�Q�h�~�~�|�{���@��������\n";	Sleep(1000);
					cout << "  �W�����B���檺��\n\n";	Sleep(1000);
					cout << "  ���F�P�§A���e�A���Q�@�H�а_\n";	Sleep(1000);
					cout << "  cpsoo���ͨM�w�}�ѯ�\n";	Sleep(1000);
					cout << "  ���A�Ҧ���������ë\n";	Sleep(1000);
					cout << "  �ߧY�ʤɤ@�ӵ���!!\n\n";
					for (int i = 0; i < player_list.size(); i++) {
						player_list.at(i)->setExp(player_list.at(i)->getLvupExp() + 10);
					}
					Sleep(4000);
					system("cls");
					current_field->display();
					if (current_field == First_floor) {
						cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
					}
				}
			}
			break;
			}

			// 1F 
			switch (current_symbol) {
			case 101:
				if (!goblin_monster_killed) {
					system("cls");
					Sleep(1000);
					cout << "\n  Goblin�G�A�٨S\n\n";
					Sleep(2000);
					cout << "  Goblin�G�q�ڨ��W��L�h\n\n";
					Sleep(2000);
					cout << "  Goblin�G�ٷQ���}�o�̰ڰڰ�\n\n";
					Sleep(2000);
					cout << "  Goblin�G���ӧڮa���ѧڦA��!!\n\n";
					Sleep(2500);
					system("cls");
					Sleep(1000);
					current_field->display();
					if (current_field == First_floor) {
						cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
					}
				}
				else if (paper_amount < 5) {
					system("cls");
					Sleep(1000);
					cout << "\n  cpsoo���͡GWait wait wait!!\n\n";
					Sleep(2000);
					cout << "  cpsoo���͡G�ڪ��Ȥ�\n\n";
					Sleep(2000);
					cout << "  cpsoo���͡G�A�٨S�䧹rrrrrrr\n\n";
					Sleep(2000);
					cout << "  cpsoo���͡G�ߧ��e�O�Q���}�o�̡I\n\n";
					Sleep(2500);
					system("cls");
					Sleep(1000);
					current_field->display();
					if (current_field == First_floor) {
						cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
					}
				}
				else {
					system("cls");
					Sleep(500);
					setCursor(3, 3);
					cout << "�q��W��...";
					Sleep(1000);
					current_field = Second_floor;
					system("cls");
					if (!second_floor_entered) {
						Welcome_2F welcome;
						welcome.run();
						system("cls");
						Sleep(500);
						second_floor_entered = true;
					}
					current_field->display();
					if (current_field == First_floor) {
						cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
					}
				}
				break;
			case 111:
				// Create a battle
				player_screen = new Menu;
				int player_list_response;
				player_screen->question_name = "�d�ݱz�������";
				player_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEnter��ܰѥ[�԰��������A��ܧ����Ы��UEsc�F�Ϊ�����Esc��h�X");
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->options.push_back(player_list.at(i)->getName());
				}
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
				}
				//Sleep(3000);
				system("cls");
				Sleep(1000);
				do {
					player_list_response = player_screen->run();
					if (player_list_response != -1) {
						choose_member.insert(player_list_response);
					}
				} while (player_list_response != -1 && choose_member.size() != player_list.size());

				if (choose_member.size() != 0) {
					vector<NovicePlayer*> choose_player;
					for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
						choose_player.push_back(player_list.at(*it));
					}
					int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
					vector<BaseMonster*> monster_list;
					for (int i = 0; i < monster_num; i++) {
						BaseMonster* goblin = new GoblinMonster;
						monster_list.push_back(goblin);
					}
					Battle* battle = new Battle(choose_player, monster_list, 0);
					system("cls");
					battle->run();
					if (battle->playerWin()) {
						goblin_monster_killed = true;
					}
					if (battle->monsterWin()) {
						cout << "   �C���Y�N����";
						Sleep(1500);
						game_end = true;
					}

					for (int i = 0; i < player_list.size(); i++) {
						if (player_list.at(i)->getHp() == 0) {
							delete player_list.at(i);
							player_list.erase(player_list.begin() + i);
							i = -1;
						}
					}
					for (int i = 0; i < monster_list.size(); i++) {
						delete monster_list.at(i);
					}
					delete battle;
				}
				delete player_screen;

				system("cls");
				current_field->display();
				if (current_field == First_floor) {
					cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
				}

				break;
			case 121:
				system("cls");
				Sleep(1000);
				setCursor(4, 2);
				cout << "�A�w�g�i�J�F";
				Sleep(2000);
				setCursor(4, 4);
				cout << "cpsoo���Ͳ��Ͱl�M��";
				Sleep(2000);
				setCursor(4, 6);
				cout << "�ɪ��G�D";
				Sleep(2000);
				setCursor(4, 8);
				cout << "�еy�ݥL��M�A�R���`�w���a�I�N�ɪŧ��|";
				Sleep(2000);
				setCursor(4, 10);
				cout << "��A�e�쥼�������Ӧa��...";
				Sleep(4000);
				int x, y;
				do {
					x = rand() % current_field->getMapSize().width;
					y = rand() % current_field->getMapSize().height;
				} while (current_field->getSymbol(x, y) != 0);
				current_field->setPosition(x, y);
				system("cls");
				Sleep(500);
				continue;
				break;
			case 131:
				if (!current_field->isStepped()) {
					system("cls");
					current_field->setGrid(current_field->getCurrentPosition(), "��");
					current_field->display();
					++paper_amount;
					setCursor(2, 22);
					cout << "���ߧA�ߨ�@�icpsoo���ͥ����w�[���ȱ�!!";
					current_field->step();
					setCursor(2, 24);
					cout << "�w�ߦ^ " << paper_amount << " �i�ȱ�";
				}
				break;
			}

			// 2F
			NotNotGame* notnotgame = nullptr;
			switch (current_symbol) {
			case 200:
				//Sleep(1000);
				system("cls");
				Sleep(500);
				setCursor(3, 3);
				cout << "�q��U��...";
				Sleep(1000);
				current_field = First_floor;
				system("cls");
				Sleep(500);
				current_field->display();
				if (current_field == First_floor) {
					cout << "  �w�ߦ^ " << paper_amount << " �i�ȱ�\n\n";
				}
				break;

			case 201:
				if (!second_floor_finish) {
					system("cls");
					End_2F End;
					End.run();
					system("cls");
					player_screen = new Menu;
					int player_list_response;
					player_screen->question_name = "�d�ݱz�������";
					player_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEnter��ܰѥ[�԰��������A��ܧ����Ы��UEsc�F�Ϊ�����Esc��h�X");
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->options.push_back(player_list.at(i)->getName());
					}
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
					}
					system("cls");
					do {
						player_list_response = player_screen->run();
						if (player_list_response != -1) {
							choose_member.insert(player_list_response);
						}
					} while (player_list_response != -1 && choose_member.size() != player_list.size());
					if (choose_member.size() != 0) {
						vector<NovicePlayer*> choose_player;
						for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
							choose_player.push_back(player_list.at(*it));
						}
						int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
						vector<BaseMonster*> monster_list;
						for (int i = 0; i < monster_num; i++) {
							BaseMonster* zombie = new ZombieMonster;
							monster_list.push_back(zombie);
						}
						Battle* battle = new Battle(choose_player, monster_list, 0);
						system("cls");
						battle->run();
						if (battle->playerWin()) {
							zombie_monster_killed = true;
							second_floor_finish = true;
							system("cls");
							Sleep(500);
							cout << "\n\n   �q��W��...";
							current_field = Third_floor;
							Sleep(1000);
							if (!third_floor_entered) {
								system("cls");
								Welcome_3F welcome;
								welcome.run();
								Sleep(500);
								third_floor_entered = true;
							}
							system("cls");
							current_field->display();
						}
						else if (battle->monsterWin()) {
							cout << "   �C���Y�N����";
							Sleep(1500);
							game_end = true;
							break;
						}
						else {
							current_field->setPosition(28, 27);
							current_field->display();
						}

						for (int i = 0; i < player_list.size(); i++) {
							if (player_list.at(i)->getHp() == 0) {
								delete player_list.at(i);
								player_list.erase(player_list.begin() + i);
								i = -1;
							}
						}
						for (int i = 0; i < monster_list.size(); i++) {
							delete monster_list.at(i);
						}
						delete battle;
					}
					delete player_screen;
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n\n   �q��W��...";
					current_field = Third_floor;
					Sleep(500);
					system("cls");
					current_field->display();
				}
				break;
			case 233:
			case 235:
			case 239:
			case 243:
			case 247:
				cout << "  �A�q����V�F�հհհհ� �Ҧ������N�Q�����I�g���";
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->minusExp(5);
				}

				break;
			case 261:
				if (!first_notnot) {
					system("cls");
					setCursor(2, 1);
					cout << "�w��I";
					Sleep(2000);
					setCursor(2, 3);
					cout << "���F�ﱵ���й������A���";
					Sleep(2000);
					setCursor(2, 5);
					cout << "CAS���ͦ��w��߬��A�]�p�F�@����E���D��";
					Sleep(2000);
					setCursor(2, 7);
					cout << "�q�L�����Y�i�~��ȵ{�A���Y�����D�ԥ��Q�z�N�Q�e�^���A���s�ѥ[�D��";
					Sleep(2000);
					setCursor(2, 9);
					cout << "�ǳƦn�F�ܡI";
					Sleep(2000);
					setCursor(2, 11);
					cout << "�H�U�O�@�ǩM��V���������D�A�Цb�ɭ������U�ŦX�D�N������A";
					Sleep(1500);
					setCursor(2, 13);
					cout << "�z���@�����������|�A";
					Sleep(1500);
					setCursor(2, 15);
					cout << "�O��i���P�A�D�ԧY�N�}�l�I";
					Sleep(2500);

					notnotgame = new NotNotGame(15);
					if (!notnotgame->run(player_list)) {
						current_field->setPosition(7, 26);
						delete notnotgame;
					}
					else {
						current_field->setPosition(9, 26);
						first_notnot = true;
						delete notnotgame;
					}
					current_field->display();
				}
				break;
			case 262:
				if (!second_notnot) {
					system("cls");
					setCursor(2, 1);
					cout << "���D�ӨӪ��A���W�F�I";
					Sleep(2000);
					setCursor(2, 3);
					cout << "�ݨ�A���e�u������{";
					Sleep(2000);
					setCursor(2, 5);
					cout << "CAS���ͨM�w�A�h���A�@�I����";
					Sleep(2000);
					setCursor(2, 7);
					cout << "�o�����D�Ƥ���y�L�h�F�I";
					Sleep(2000);
					setCursor(2, 9);
					cout << "���L�۫H�A���w�i�H����@�˶��Q�q�L��!!";
					Sleep(2500);

					notnotgame = new NotNotGame(25);
					if (!notnotgame->run(player_list)) {
						current_field->setPosition(19, 26);
						delete notnotgame;
						continue;
					}
					else {
						current_field->setPosition(18, 27);
						second_notnot = true;
						delete notnotgame;
						continue;
					}
				}
				break;
			case 271:
				system("cls");
				Sleep(1000);
				setCursor(4, 2);
				cout << "�ӤU������J��(�d)��(��)��cpsoo����";
				Sleep(2000);
				setCursor(4, 4);
				cout << "���p�ߪ��L�Y�N�A�ҳB���Ŷ���F�_��";
				Sleep(2000);
				setCursor(4, 6);
				cout << "�NLSD�s�����t�@��";
				Sleep(2000);
				setCursor(4, 8);
				cout << "�P�A�}�U�ذ_�F�ɪŨ��Y";
				Sleep(2000);
				setCursor(4, 10);
				cout << "�y�ݤ@�|�A�Ŷ��Y�N����...";
				Sleep(4000);
				int x, y;
				do {
					x = rand() % current_field->getMapSize().width;
					y = rand() % current_field->getMapSize().height;
				} while (current_field->getSymbol(x, y) != 0);
				current_field->setPosition(x, y);
				system("cls");
				Sleep(500);
				continue;
				break;
			}

			// 3F
			switch (current_symbol) {
			case 300:
				system("cls");
				Sleep(500);
				setCursor(3, 3);
				cout << "�q��U��...";
				Sleep(1000);
				current_field = Second_floor;
				system("cls");
				Sleep(500);
				current_field->display();
				break;

			case 301:
				player_screen = new Menu;
				int player_list_response;
				player_screen->question_name = "�d�ݱz�������";
				player_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEnter��ܰѥ[�԰��������A��ܧ����Ы��UEsc�F�Ϊ�����Esc��h�X");
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->options.push_back(player_list.at(i)->getName());
				}
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
				}
				system("cls");
				do {
					player_list_response = player_screen->run();
					if (player_list_response != -1) {
						choose_member.insert(player_list_response);
					}
				} while (player_list_response != -1 && choose_member.size() != player_list.size());

				if (choose_member.size() != 0) {
					vector<NovicePlayer*> choose_player;
					for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
						choose_player.push_back(player_list.at(*it));
					}
					int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
					vector<BaseMonster*> monster_list;
					for (int i = 0; i < monster_num; i++) {
						BaseMonster* jwmonster = new JWMonster;
						monster_list.push_back(jwmonster);
					}
					Battle* battle = new Battle(choose_player, monster_list, 0);
					system("cls");
					battle->run();
					if (battle->playerWin()) {
						system("cls");
						EndScreen end_screen;
						game_end = true;
						break;
					}
					else if (battle->monsterWin()) {
						cout << "   �C���Y�N����";
						Sleep(1500);
						game_end = true;
						break;
					}
					else {
						current_field->display();
					}

					for (int i = 0; i < player_list.size(); i++) {
						if (player_list.at(i)->getHp() == 0) {
							delete player_list.at(i);
							player_list.erase(player_list.begin() + i);
							i = -1;
						}
					}
					for (int i = 0; i < monster_list.size(); i++) {
						delete monster_list.at(i);
					}
					delete battle;
				}
				delete player_screen;

				break;
			case 311:
				system("cls");
				current_field->setPosition(1, 3);
				current_field->display();
				current_field->setPosition(4, 2);
				current_field->display();
				current_field->setPosition(3, 8);
				current_field->display();
				current_field->setPosition(1, 6);
				current_field->display();
				current_field->setPosition(10, 7);
				current_field->display();
				break;
			case 312:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "�ӤU�s������פu�{";
				Sleep(1500);
				setCursor(3, 3);
				cout << "���p�߹�Ѫ�O�p�}�F�Ӭ}";
				Sleep(1500);
				setCursor(3, 5);
				cout << "��m";
				Sleep(1500);
				setCursor(3, 7);
				cout << "�Ӧn�N�b�A���}�U";
				Sleep(1500);
				setCursor(3, 9);
				cout << "�p��!!!";
				Sleep(1000);
				system("cls");
				current_field = Second_floor;
				current_field->setPosition(15, 20);
				current_field->display();
				break;
			case 313:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "�x�n�s�骺�j�B";
				Sleep(1500);
				setCursor(3, 3);
				cout << "�S�j�S��";
				Sleep(1500);
				setCursor(3, 5);
				cout << "�T�F���ӬƦ�";
				Sleep(1500);
				setCursor(3, 7);
				cout << "�į}�F�A�Y�W���γ�";
				Sleep(1500);
				setCursor(3, 9);
				cout << "......";
				Sleep(1500);
				setCursor(3, 11);
				cout << "�j����A����R�F�n�@�q��";
				Sleep(1500);
				setCursor(3, 13);
				cout << "���F���ֶ�";
				Sleep(3000);
				setCursor(3, 16);
				cout << "�Ҧ��H��q�֤F20�I";
				Sleep(2500);
				system("cls");
				current_field->setPosition(2, 9);
				current_field->display();
				break;
			case 314:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "�ש��i�o�@�檺�z���W�F";
				Sleep(1500);
				setCursor(3, 3);
				cout << "���M�o�̵M���O���T���K�D";
				Sleep(1500);
				setCursor(3, 5);
				cout << "�p�G�w�g��ܤ[���ܰ������ܱz";
				Sleep(1500);
				setCursor(3, 7);
				cout << "�O�Ӧ����s�h���X�B�����O�ȱo�x";
				Sleep(1500);
				setCursor(3, 9);
				cout << "���M�A�}�U���a�O";
				Sleep(1500);
				setCursor(3, 11);
				cout << "���w���}�@�ӵL�k���^���}";
				Sleep(1500);
				setCursor(3, 13);
				cout << "�Фp�ߡA�L���Y�N�}�l...";
				current_field = Second_floor;
				Sleep(2500);
				system("cls");
				current_field->setPosition(27, 13);
				current_field->display();
				break;
			case 315:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "���Ѫ����p���`���M��";
				Sleep(1500);
				setCursor(3, 3);
				cout << "�N��ڭ̪��C�@�������@��";
				Sleep(1500);
				setCursor(3, 5);
				cout << "�p�G�A�٨S�o�{�����Фp�߽�U���ӨC�@�B";
				Sleep(1500);
				setCursor(3, 7);
				cout << "�p�G�w�g�o�{�F";
				Sleep(1500);
				setCursor(3, 9);
				cout << "���ߧA";
				Sleep(1500);
				setCursor(3, 11);
				cout << "�o�̬O�ּƩ|���M���|�񪺫Ѥl";
				Sleep(1500);
				setCursor(3, 13);
				cout << "���F�A�����I�j�A�A�n����í�F...";
				Sleep(2500);
				system("cls");
				current_field->setPosition(1, 8);
				current_field->display();
				break;
			}
		}
		if (game_end) {
			break;
		}
		// Let user press a key
		{
			do {
				press = _getch();
				if (press == 224) {
					press = _getch();
				}
				switch (press) {
				case 75:
				case 'A':
					press = 'a';
					break;
				case 77:
				case 'D':
					press = 'd';
					break;
				case 72:
				case 'W':
					press = 'w';
					break;
				case 80:
				case 'S':
					press = 's';
					break;
				case 'm':
					serialize();
					break;
				case 'p':
					player_screen = new Menu;
					int player_list_response;
					player_screen->question_name = "�d�ݱz�������";
					player_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEsc��h�X");
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->options.push_back(player_list.at(i)->getName());
					}
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
					}
					system("cls");
					player_list_response = player_screen->run();
					while (player_list_response != -1) {
						player_list_response = player_screen->run();
					}
					delete player_screen;
					system("cls");
					current_field->display();
					break;
				case 'b':
					system("cls");
					backpack.display();
					system("cls");
					current_field->display();
					break;
				case 'v':
					system("cls");
					if (current_field == First_floor) {
						legend_1F legend;
						legend.display();
					}
					else if (current_field == Second_floor) {
						legend_2F legend;
						legend.display();
					}
					else if (current_field == Third_floor) {
						legend_3F legend;
						legend.display();
					}
					system("cls");
					current_field->display();
					break;
				}
			} while (!current_field->move(press) && press != 27);
		}

		if (press == 27) {
			break;
		}
		//	hot key in field screen end

		// moving
		++step_count;

		// detect current_symbol after moving
		current_symbol = current_field->getSymbol();

		int temp_level_sigma = 0;
		for (int i = 0; i < player_list.size(); i++) {
			temp_level_sigma += player_list.at(i)->getLevel();
		}
		if (temp_level_sigma > all_player_level_sigma) {
			for (int i = 0; i < temp_level_sigma - all_player_level_sigma; i++) {
				backpack.addWeightLimit();
			}
		}

		all_player_level_sigma = temp_level_sigma;

	}
	return game_end;
}

void Game::serialize()
{
	fstream file("record.txt", ios::out);

	// players
	for (int i = 0; i < player_list.size(); i++) {
		file << player_list.at(i)->serialize() << endl;
	}

	// backpack
	file << backpack.serialize() << endl;

	// current_field
	if (current_field == First_floor) {
		file << "@current_field$First_floor$#" << endl;
	}
	else if (current_field == Second_floor) {
		file << "@current_field$Second_floor$#" << endl;
	}
	else if (current_field == Third_floor) {
		file << "@current_field$Third_floor$#" << endl;
	}

	// positions in each field
	stringstream s1, s2;
	s1 << First_floor->getCurrentPosition().x;
	s2 << First_floor->getCurrentPosition().y;
	file << ("@First_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	s1 << Second_floor->getCurrentPosition().x;
	s2 << Second_floor->getCurrentPosition().y;
	file << ("@Second_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	s1 << Third_floor->getCurrentPosition().x;
	s2 << Third_floor->getCurrentPosition().y;
	file << ("@Third_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	file << "@Game$ " << endl;
	file << paper_amount << ' ' << all_player_level_sigma << ' ' << second_floor_entered << ' ' << third_floor_entered << ' '
		<< second_floor_finish << ' ' << first_notnot << ' ' << second_notnot << ' '
		<< goblin_monster_killed << ' ' << zombie_monster_killed << endl;

	file << "#end#";
	file.close();

}

void Game::unserialize()
{
	// destructor

	fstream file("record.txt", ios::in);

	string input;
	string label;
	stringstream ss;
	while (1) {
		getline(file, input);
		if (input.length() == 0) {
			break;
		}
		int begin, end;
		begin = input.find('@');
		end = input.find('$');
		if (begin == -1 || end == -1) {
			break;
		}
		label = string(input, begin + 1, end - begin - 1);
		if (label == "Game") {
			break;
		}
		if (label == "NovicePlayer") {
			player_list.push_back(NovicePlayer::unserialize(input));
		}
		else if (label == "OrcPlayer") {
			player_list.push_back(OrcPlayer::unserialize(input));
		}
		else if (label == "KnightPlayer") {
			player_list.push_back(KnightPlayer::unserialize(input));
		}
		else if (label == "MagicianPlayer") {
			player_list.push_back(MagicianPlayer::unserialize(input));
		}
		else if (label == "Backpack") {
			backpack.unserialize(input);
		}
		else if (input == "@current_field$First_floor$#") {
			current_field = First_floor;
		}
		else if (input == "@current_field$Second_floor$#") {
			current_field = Second_floor;
		}
		else if (input == "@current_field$Third_floor$#") {
			current_field = Third_floor;
		}
		else if (label == "First_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			First_floor->setPosition(x, y);
		}
		else if (label == "Second_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			Second_floor->setPosition(x, y);
		}
		else if (label == "Third_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			Third_floor->setPosition(x, y);
		}
	}

	file >> paper_amount >> all_player_level_sigma >> second_floor_entered >> third_floor_entered
		>> second_floor_finish >> first_notnot >> second_notnot
		>> goblin_monster_killed >> zombie_monster_killed;

}

Game::Game()
{
	srand(time(NULL));

	backpack.setPlayerList(&player_list);

	// Main_Menu //
	{
		Main_Menu.question_name = "�C���D���";

		Main_Menu.instruction.push_back("�w��i�J�ڪ�RPG�I");
		Main_Menu.instruction.push_back("�o�O�@�ں�߻s�@���C��");
		Main_Menu.instruction.push_back("�a�z����p�j�@�W���@�֪��s�A�j�ǥͬ�");
		Main_Menu.instruction.push_back("");
		Main_Menu.instruction.push_back("�ХH��L�����䲾�ʺ���СA�åH Enter ��ܥ\��");
		Main_Menu.instruction.push_back("");
		Main_Menu.instruction.push_back("�ǳƦn�F�ܡH���N���ڭ̶}�l�a~~");

		Main_Menu.options.push_back("�i�J�C��");
		Main_Menu.options.push_back("���J�s��");
		Main_Menu.options.push_back("�h�@�@�X");

		Main_Menu.option_descriptions.push_back("���ڭ��ڨB��J�������@�ɪﱵ�D�ԧa");
		Main_Menu.option_descriptions.push_back("�q�L�h�������A���X�o");
		Main_Menu.option_descriptions.push_back("���~��ǳƴ����o:D");
	}

	store = new Store(&backpack, &money);
}

Game::~Game()
{
	// delete player series objects //
	for (int i = 0; i < player_list.size(); i++) {
		delete player_list.at(i);
	}

	delete store;

	delete First_floor;
	delete Second_floor;
	delete Third_floor;
}

void Game::run()
{
	int main_menu_chosen;
	bool close = false;
	while (!close) {	// main menu begin
		system("cls");
		main_menu_chosen = Main_Menu.run();

		// options of main menu //
		switch (main_menu_chosen) {
		case 0:	// main_menu_chosen == 0 begin
			system("cls");

			if (reset) {
				if (player_list.size() > 0) {
					for (int i = 0; i < player_list.size(); i++) {
						delete player_list.at(i);
					}
					player_list.clear();
				}

				generatePlayers();

				initializeFirstFloor();
				initializeSecondFloor();
				initializeThirdFloor();

				current_field = First_floor;

				backpack.clear();

				money = 0;
				paper_amount = 0;
				all_player_level_sigma = 0;

				second_floor_entered = false;
				third_floor_entered = false;

				second_floor_finish = false;

				first_notnot = false;
				second_notnot = false;

				goblin_monster_killed = false;
				zombie_monster_killed = false;

				Welcome_1F welcome;
				system("cls");
				welcome.run();
				system("cls");
			}

			reset = play();

			break;	// main_menu_chosen == 0 end

		case 1:
			initializeFirstFloor();
			initializeSecondFloor();
			initializeThirdFloor();
			unserialize();
			reset = play();

			break;
		case 2:
			close = true;
		}

	}	// main menu end

}
