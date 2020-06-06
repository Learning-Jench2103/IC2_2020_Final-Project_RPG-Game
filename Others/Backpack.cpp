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

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
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
	result += ("效果 : " + backpack.at(index)->effects) + "\n";
	result += ("     介紹 : " + backpack.at(index)->description) + "\n";
	/* weight */
	ss << backpack.at(index)->weight;
	result += ("     重量 : " + ss.str()) + "\n";
	ss.str("");	ss.clear();
	/* level_required */
	/*
	ss << backpack.at(index)->level_required;
	result += ("     等級限制 = " + ss.str()) + "\n";
	ss.str("");	ss.clear();
	*/
	/* need_hands */
	if (backpack.at(index)->need_hands == 1) {
		result += "     需以1支手使用\n";
	}
	else if (backpack.at(index)->need_hands == 2) {
		result += "     需以2支手使用\n";
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

		backpack_screen->question_name = "查看您的背包";

		string volumn = "容量：";
		stringstream ss;
		ss << getCurrentBackpackWeight();
		volumn += ss.str(); ss.str(""); ss.clear();
		volumn += '/';
		ss << getBackpackWeightLimit();
		volumn += ss.str(); ss.str(""); ss.clear();

		backpack_screen->instruction.push_back(volumn);
		backpack_screen->instruction.push_back("");

		if (showBackpack().size() != 0) {
			backpack_screen->instruction.push_back("請以↑↓鍵移動游標，並以Esc鍵退出");
			backpack_screen->options = showBackpack();

			for (int i = 0; i < backpack_screen->options.size(); i++) {
				backpack_screen->option_descriptions.push_back(showItemInfo(i));
			}
		}
		else {
			backpack_screen->instruction.push_back("您的背包還沒有東西，多放點物資進來吧~~");
			backpack_screen->options.push_back("");
			backpack_screen->option_descriptions.push_back("這裡空空依舊，等待您來充實");
		}
		system("cls");

		backpack_response = backpack_screen->run();

		if (backpack_response == -1) {
			break;
		}

		if (showBackpack().size() != 0) {
			Menu* player_screen = new Menu;
			int player_list_response;
			player_screen->question_name = "查看您的隊伍成員";
			player_screen->instruction.push_back("請以↑↓鍵移動游標並以Enter選擇欲裝備的隊員，或以Esc鍵退出");
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
					cout << "  裝備失敗，請確認您的這位隊員有足夠的空手拿著，或您的等級已經可以裝備這項物品";
					Sleep(1000);
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n	裝備成功!!";
					Sleep(1000);
				}
				break;
			case 'a':
				if (!player_list->at(player_list_response)->equipArmor(static_cast<ArmorItem*>(item), this)) {
					putItem(item);
					cout << "  裝備失敗，請確認您的這位隊員有足夠的空手得以裝備它";
					Sleep(1000);
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n	裝備成功!!";
					Sleep(1000);
				}
				break;
			case 'c':
				if (player_list->at(player_list_response)->getLevel() < static_cast<ConsumableItem*>(item)->level_required) {
					cout << "  等級不足，無法取用!!";
					putItem(item);
					Sleep(1000);
				}
				else {
					player_list->at(player_list_response)->useConsumable(static_cast<ConsumableItem*>(item));
					system("cls");
					Sleep(500);
					cout << "\n	飲用完畢!!";
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
