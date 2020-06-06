#include "Backpack.h"
#include "../Items/base/Item.h"
#include "../Items/Armor_Armour.h"
#include "../Items/Armor_GoldenShield.h"
#include "../Items/Consumable_LifePotion.h"
#include "../Items/Consumable_MagicPotion.h"
#include "../Items/Weapon_DragonKillFalchion.h"
#include "../Items/Weapon_SkywardSword.h"
#include "../Players/NovicePlayer.h"
#include "Menu.h"
#include <sstream>
#include <Windows.h>

void Backpack::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// �N��m�]�b (x,y) ���a��C
	SetConsoleCursorPosition(hin, pos);
}

Backpack::Backpack()
{
	backpack_weight_limit = 40;
}

Backpack::~Backpack()
{
	for (int i = 0; i < backpack.size(); i++) {
		delete backpack.at(i);
	}
}

void Backpack::setPlayerList(vector<NovicePlayer*>* player_list)
{
	Backpack::player_list = player_list;
}

/*
Backpack::Backpack(int backpack_weight_limit)
{
	Backpack::backpack_weight_limit = backpack_weight_limit;
}
*/

bool Backpack::putItem(Item* item)
{
	if (backpack_weight >= backpack_weight_limit) {
		return false;
	}
	backpack.push_back(item);
	backpack_weight += item->weight;
	return true;
}

Item* Backpack::takeItem(int index)
{
	if (index >= backpack.size()) {
		return nullptr;
	}
	Item* taken = backpack.at(index);
	backpack.erase(backpack.begin() + index);
	backpack_weight -= taken->weight;
	return taken;
}

bool Backpack::setWeightLimit(int new_weight_limit)
{
	if (new_weight_limit < backpack_weight) {
		return false;
	}
	backpack_weight_limit = new_weight_limit;
	return true;
}

void Backpack::addWeightLimit()
{
	backpack_weight_limit += 10;
}

int Backpack::getCurrentBackpackWeight(void) const
{
	return backpack_weight;
}

int Backpack::getBackpackWeightLimit(void) const
{
	return backpack_weight_limit;
}

vector<string> Backpack::showBackpack(void) const
{
	vector<string> result;
	for (int i = 0; i < backpack.size(); i++) {
		result.push_back(backpack.at(i)->name);
	}
	return result;
}

string Backpack::showItemInfo(int index) const
{
	string result;
	stringstream ss;
	result += ("�ĪG : " + backpack.at(index)->effects) + "\n";
	result += ("     ���� : " + backpack.at(index)->description) + "\n";
	/* weight */
	ss << backpack.at(index)->weight;
	result += ("     ���q : " + ss.str()) + "\n";
	ss.str("");	ss.clear();
	/* level_required */
	/*
	ss << backpack.at(index)->level_required;
	result += ("     ���ŭ��� = " + ss.str()) + "\n";
	ss.str("");	ss.clear();
	*/
	/* need_hands */
	if (backpack.at(index)->need_hands == 1) {
		result += "     �ݥH1���ϥ�\n";
	}
	else if (backpack.at(index)->need_hands == 2) {
		result += "     �ݥH2���ϥ�\n";
	}
	else if (backpack.at(index)->need_hands == 0) {
		result += "                                    \n";
	}

	return result;
}

int Backpack::getItemAmount(void) const
{
	return backpack.size();
}

void Backpack::display()
{
	int backpack_response = 0;
	while (backpack_response != 1) {
		Menu* backpack_screen = new Menu;

		backpack_screen->question_name = "�d�ݱz���I�]";

		string volumn = "�e�q�G";
		stringstream ss;
		ss << getCurrentBackpackWeight();
		volumn += ss.str(); ss.str(""); ss.clear();
		volumn += '/';
		ss << getBackpackWeightLimit();
		volumn += ss.str(); ss.str(""); ss.clear();

		backpack_screen->instruction.push_back(volumn);
		backpack_screen->instruction.push_back("");

		if (showBackpack().size() != 0) {
			backpack_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEsc��h�X");
			backpack_screen->options = showBackpack();

			for (int i = 0; i < backpack_screen->options.size(); i++) {
				backpack_screen->option_descriptions.push_back(showItemInfo(i));
			}
		}
		else {
			backpack_screen->instruction.push_back("�z���I�]�٨S���F��A�h���I����i�ӧa~~");
			backpack_screen->options.push_back("");
			backpack_screen->option_descriptions.push_back("�o�̪ŪŨ��¡A���ݱz�ӥR��");
		}
		system("cls");

		backpack_response = backpack_screen->run();

		if (backpack_response == -1) {
			break;
		}

		if (showBackpack().size() != 0) {
			Menu* player_screen = new Menu;
			int player_list_response;
			player_screen->question_name = "�d�ݱz�������";
			player_screen->instruction.push_back("�ХH�����䲾�ʴ�ШåHEnter��ܱ��˳ƪ������A�ΥHEsc��h�X");
			for (int i = 0; i < player_list->size(); i++) {
				player_screen->options.push_back(player_list->at(i)->getName());
			}
			for (int i = 0; i < player_list->size(); i++) {
				player_screen->option_descriptions.push_back(player_list->at(i)->showInfo());
			}
			system("cls");
			player_list_response = player_screen->run();
			if (player_list_response == -1) {
				continue;
			}


			Item* item = takeItem(backpack_response);

			switch (item->type) {
			case 'w':
				if (!player_list->at(player_list_response)->equipWeapon(static_cast<WeaponItem*>(item), this)) {
					putItem(item);
					cout << "  �˳ƥ��ѡA�нT�{�z���o�춤�����������Ť⮳�ۡA�αz�����Ťw�g�i�H�˳Ƴo�����~";
					Sleep(1000);
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n	�˳Ʀ��\!!";
					Sleep(1000);
				}
				break;
			case 'a':
				if (!player_list->at(player_list_response)->equipArmor(static_cast<ArmorItem*>(item), this)) {
					putItem(item);
					cout << "  �˳ƥ��ѡA�нT�{�z���o�춤�����������Ť�o�H�˳ƥ�";
					Sleep(1000);
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n	�˳Ʀ��\!!";
					Sleep(1000);
				}
				break;
			case 'c':
				if (player_list->at(player_list_response)->getLevel() < static_cast<ConsumableItem*>(item)->level_required) {
					cout << "  ���Ť����A�L�k����!!";
					putItem(item);
					Sleep(1000);
				}
				else {
					player_list->at(player_list_response)->useConsumable(static_cast<ConsumableItem*>(item));
					system("cls");
					Sleep(500);
					cout << "\n	���Χ���!!";
					Sleep(1000);
				}
				break;
			}
			delete player_screen;
		}
		delete backpack_screen;

	}
}

void Backpack::clear()
{
	for (int i = 0; i < backpack.size(); i++) {
		delete backpack.at(i);
	}
	backpack.clear();
	backpack_weight = 0;
	backpack_weight_limit = 40;
}

string Backpack::serialize() const
{
	stringstream ss;
	string result = "@Backpack$";
	ss << backpack_weight;
	result += (ss.str() + '$'); ss.str(""); ss.clear();
	ss << backpack_weight_limit;
	result += (ss.str() + '$'); ss.str(""); ss.clear();
	for (int i = 0; i < backpack.size(); i++) {
		result += backpack.at(i)->getEngName();
		result += '$';
	}
	result += '#';
	return result;
}

void Backpack::unserialize(string record)
{
	clear();

	stringstream ss;
	int last_position = record.find('$');
	int current_position = record.find('$', last_position + 1);
	ss << string(record, last_position + 1, current_position - last_position - 1);
	ss >> backpack_weight; ss.str(""); ss.clear();

	last_position = current_position;
	current_position = record.find('$', last_position + 1);
	ss << string(record, last_position + 1, current_position - last_position - 1);
	ss >> backpack_weight_limit; ss.str(""); ss.clear();

	while (record.at(current_position + 1) != '#') {
		last_position = current_position;
		current_position = record.find('$', last_position + 1);

		if (string(record, last_position + 1, current_position - last_position - 1) == "Armour") {
			backpack.push_back(new Armour);
		}
		else if (string(record, last_position + 1, current_position - last_position - 1) == "GoldenShield") {
			backpack.push_back(new GoldenShield);
		}
		else if (string(record, last_position + 1, current_position - last_position - 1) == "LifePotion") {
			backpack.push_back(new LifePotion);
		}
		else if (string(record, last_position + 1, current_position - last_position - 1) == "MagicPotion") {
			backpack.push_back(new MagicPotion);
		}
		else if (string(record, last_position + 1, current_position - last_position - 1) == "DragonKillFalchion") {
			backpack.push_back(new DragonKillFalchion);
		}
		else if (string(record, last_position + 1, current_position - last_position - 1) == "SkywardSword") {
			backpack.push_back(new SkywardSword);
		}
	}

}
