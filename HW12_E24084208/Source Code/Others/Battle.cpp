#include "Battle.h"
#include "../Players/NovicePlayer.h"
#include "../Monsters/BaseMonster.h"
#include <conio.h>

inline void Battle::reward()
{
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list[i]->type == 'p' && action_list[i]->alive) {
			static_cast<NovicePlayer*>(action_list[i]->instance)->addExp((int)((double)monster_number / player_number * 10));
		}
	}
}

void Battle::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
	SetConsoleCursorPosition(hin, pos);
}

Battle::Battle(vector<NovicePlayer*> player, vector<BaseMonster*> monster, int turn_limit = 0)
{
	Battle::turn_limit = turn_limit;
	action_list.resize(player.size() + monster.size());
	for (int i = 0; i < player.size(); i++) {
		action_list.at(i) = new Character;
		action_list.at(i)->type = 'p';
		action_list.at(i)->alive = true;
		action_list.at(i)->instance = player.at(i);
	}
	for (int j = 0; j < monster.size(); j++) {
		action_list.at(player.size() + j) = new Character;
		action_list.at(player.size() + j)->type = 'm';
		action_list.at(player.size() + j)->alive = true;
		action_list.at(player.size() + j)->instance = monster.at(j);
	}

	player_number = player.size();
	monster_number = monster.size();
}

Battle::~Battle()
{
	for (int i = 0; i < action_list.size(); i++) {
		delete action_list[i];
	}
}

void Battle::run()
{
	system("cls");

	int response = 0;

	do {
		if (action_list.at(current_actor)->type == 'p') {
			for (int opponent = player_number; opponent < action_list.size(); opponent++) {
				system("cls");
				setCursor(3, 1);
				cout << "�m��M�{���n";
				NovicePlayer* player = static_cast<NovicePlayer*>(action_list.at(current_actor)->instance);
				vector<string> playerInfo = player->getInfoArray();
				for (int i = 0; i < playerInfo.size(); i++) {
					setCursor(2, 3 + i);
					cout << playerInfo.at(i);
				}
				setCursor(47, 7);
				cout << "VS.";

				BaseMonster* monster = static_cast<BaseMonster*>(action_list.at(opponent)->instance);
				vector<string> monsterInfo = monster->getInfo();
				for (int i = 0; i < monsterInfo.size(); i++) {
					setCursor(52, 3 + i);
					cout << monsterInfo.at(i);	// clear Console screen
				}

				setCursor(4, 5 + playerInfo.size());
				cout << "�ϥίS��ޯ�A�W�}�Ы�'s'   �����W�}�Ы� Enter   �����W���Ы� Esc";

				do {
					response = _getch();
					if (response == 224) {
						response = _getch();
					}
				} while (!(response == 's' || response == 'S' || response == 13 || response == 27));
				if (response == 27) {
					break;
				}
				attack(*(action_list.at(current_actor)), *(action_list.at(opponent)), response == 'y' ? true : false);
				setCursor(4, 7 + playerInfo.size());
				printf("%c[2K", 27);
				setCursor(4, 7 + playerInfo.size());
				cout << "�������A�еy��...";
				Sleep(1000);
			}
		}	// end if ('p'->'m')
		else {
			for (int opponent = 0; opponent < player_number; opponent++) {
				system("cls");
				setCursor(3, 1);
				cout << "�m��M�{���n";
				BaseMonster* monster = static_cast<BaseMonster*>(action_list.at(current_actor)->instance);
				vector<string> monsterInfo = monster->getInfo();
				for (int i = 0; i < monsterInfo.size(); i++) {
					setCursor(2, 3 + i);
					printf("%c[2K", 27);
					setCursor(2, 3 + i);
					cout << monsterInfo.at(i);	// clear Console screen
				}
				setCursor(47, 7);
				cout << "VS.";

				NovicePlayer* player = static_cast<NovicePlayer*>(action_list.at(opponent)->instance);
				vector<string> playerInfo = player->getInfoArray();
				for (int i = 0; i < playerInfo.size(); i++) {
					setCursor(52, 3 + i);
					cout << playerInfo.at(i);	// clear Console screen
				}
				setCursor(4, 5 + playerInfo.size());
				cout << "�ϥίS��ޯ�A�W�}�Ы�'s'   �����W�}�Ы� Enter   �����W���Ы� Esc";
				do {
					response = _getch();
					if (response == 224) {
						response = _getch();
					}
				} while (!(response == 's' || response == 'S' || response == 13 || response == 27));
				if (response == 27) {
					break;
				}
				attack(*(action_list.at(current_actor)), *(action_list.at(opponent)), response == 'y' ? true : false);
				setCursor(4, 7 + playerInfo.size());
				printf("%c[2K", 27);
				setCursor(4, 7 + playerInfo.size());
				cout << "�������A�еy��...";
				Sleep(1000);
			}
		}
	} while (nextActor() && response != 27 && !playerWin() && !monsterWin());

	system("cls");
	int lowest_line = 1;
	setCursor(3, 1);
	cout << "======�԰����G======";
	for (int i = 0; i < action_list.size(); i++) {
		vector<string> info;
		++lowest_line;
		if (action_list.at(i)->type == 'p') {
			info = static_cast<NovicePlayer*>(action_list.at(i)->instance)->getInfoArray();
		}
		else {
			info = static_cast<BaseMonster*>(action_list.at(i)->instance)->getInfo();
		}
		for (int j = 0; j < info.size(); j++) {
			setCursor(1, 1 + lowest_line);
			cout << info.at(j);
			++lowest_line;
		}
	}

	if (playerWin()) {
		setCursor(1, 1 + ((++lowest_line)++));
		cout << "�z������i�{�F�j�j�԰��O�A�ԳӤF�Ҧ����I";
		reward();
		setCursor(1, 1 + (lowest_line++));
		cout << "�C��W�����i�̭̳��N�o��" << (int)((double)monster_number / player_number * 20) << "�I�g��ȧ@�����y�I";
	}
	else if (monsterWin()) {
		setCursor(1, 1 + lowest_line);
		cout << "�z������";
		++lowest_line;
		Sleep(1000);
		setCursor(1, 1 + lowest_line);
		cout << "�b��誺�}�x�԰���";
		++lowest_line;
		Sleep(1000);
		setCursor(1, 1 + lowest_line);
		cout << "�w�����^�i�묹�F...";
		Sleep(800);
		cout << "...";
		Sleep(800);
		cout << "...";
		++lowest_line;
	}
	else {
		setCursor(1, 1 + (lowest_line++));
		cout << "�Ȯɪ��𮧬O���F�U�����ӧQ";
		setCursor(1, 1 + (lowest_line++));
		cout << "���ݤU���F���W�X�}�o�Ӫ��A!!";
	}
	Sleep(3000);
}

bool Battle::nextActor(void)
{
	if (current_turn == turn_limit - 1 && current_actor == action_list.size() - 1) {
		return false;
	}

	if (playerWin()) {
		reward();
		return false;
	}

	if (current_actor == action_list.size() - 1) {
		current_actor = 0;
		++current_turn;
	}
	else {
		++current_actor;
	}

	if (!action_list[current_actor]->alive) {
		return nextActor();
	}
	else {
		return true;
	}
}

int Battle::getCurrentTurn(void) const
{
	return current_turn;
}

int Battle::getTurnLimit(void) const
{
	return turn_limit;
}

bool Battle::attack(Character& actor_1, Character& actor_2, bool specialSkill = false)
{
	NovicePlayer* p_ptr;
	BaseMonster* m_ptr;

	if (actor_1.type == 'm' && actor_2.type == 'p') {
		m_ptr = static_cast<BaseMonster*>(actor_1.instance);
		p_ptr = static_cast<NovicePlayer*>(actor_2.instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
		p_ptr->decreaseHp((double)m_ptr->attack / p_ptr->getDefense() * 8);

		if (p_ptr->getHp() == 0) {
			actor_2.alive = false;
		}
		return true;
	}
	else if (actor_1.type == 'p' && actor_2.type == 'm') {
		p_ptr = static_cast<NovicePlayer*>(actor_1.instance);
		m_ptr = static_cast<BaseMonster*>(actor_2.instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
		m_ptr->decreaseHp((double)p_ptr->getAttack() / m_ptr->defense * 16);

		if (m_ptr->getHP() == 0) {
			actor_2.alive = false;
		}
		return true;
	}
	return false;
}

int Battle::getPlayerNumber(void) const
{
	return player_number;
}

int Battle::getPlayerNumber(bool alive) const
{
	int count = 0;
	for (int i = 0; i < player_number; i++) {
		if (action_list[i]->alive) {
			count++;
		}
	}

	if (alive) {
		return count;
	}
	else {
		return (player_number - count);
	}
}

int Battle::getMonsterNumber(void) const
{
	return monster_number;
}

int Battle::getMonsterNumber(bool alive) const
{
	int count = 0;
	for (int i = 0; i < monster_number; i++) {
		if (action_list[i + player_number]->alive) {
			count++;
		}
	}

	if (alive) {
		return count;
	}
	else {
		return (monster_number - count);
	}
}

Character* Battle::getCurrentActor(void) const
{
	return action_list.at(current_actor);
}

vector<Character*> Battle::getPlayers(void) const
{
	vector<Character*> result;
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'p') {
			result.push_back(action_list.at(i));
		}
	}
	return result;
}

vector<Character*> Battle::getMonsters(void) const
{
	vector<Character*> result;
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'm') {
			result.push_back(action_list.at(i));
		}
	}
	return result;
}

vector<Character*> Battle::getOpponents(void) const
{
	vector<Character*> result;
	if (action_list.at(current_actor)->type == 'p') {
		for (int i = 0; i < action_list.size(); i++) {
			if (action_list.at(i)->type == 'm' && action_list.at(i)->alive) {
				result.push_back(action_list.at(i));
			}
		}
	}
	else {
		for (int i = 0; i < action_list.size(); i++) {
			if (action_list.at(i)->type == 'p' && action_list.at(i)->alive) {
				result.push_back(action_list.at(i));
			}
		}
	}
	return result;
}

bool Battle::playerWin()
{
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'm' && action_list.at(i)->alive) {
			return false;
		}
	}
	return true;
}

bool Battle::monsterWin()
{
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'p' && action_list.at(i)->alive) {
			return false;
		}
	}
	return true;
}

