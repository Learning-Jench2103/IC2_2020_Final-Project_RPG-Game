#include "Store.h"
#include <Windows.h>
#include <sstream>
using namespace std;

void Store::initializeStoreMenu()
{
	menu = new Menu;

	menu->question_name = "商店街";
	menu->instruction.push_back("");
	menu->instruction.push_back("");
	menu->instruction.push_back("請以↑↓鍵移動游標至欲購買的品項，按下Enter購買");
	menu->instruction.push_back("購買前請注意每個用品的等級限制，只有隊伍中達到該等級的成員才能使用哦");
	menu->instruction.push_back("本店價格公道不坑殺消費者，請安心選購!!");
	menu->instruction.push_back("提醒您，我們不提供退貨服務，商品一經售出無法取消~~");

	menu->options.push_back("倚 天 劍--售價20元");
	menu->options.push_back("屠 龍 刀--售價35元");
	menu->options.push_back("盔　　甲--售價15元");
	menu->options.push_back("金 鐘 罩--售價30元");
	menu->options.push_back("生命之水--售價25元");
	menu->options.push_back("魔法藥水--售價40元");
	menu->options.push_back("查看您的背包");

	menu->option_descriptions.push_back("攻擊力增強10點，讓您面對敵人時更具威脅。等級2以上可配備，重量20，以單手使用");
	menu->option_descriptions.push_back("攻擊力增加25點，讓您面對強敵無所畏懼。等級4以上方可配備，重量30，以雙手使用");
	menu->option_descriptions.push_back("裝備後可增加5點防禦力。等級2以上可裝備，重量15");
	menu->option_descriptions.push_back("裝備後可增加10點防禦力，讓您打鬥時無後顧之憂。等級4以上可使用，重量20");
	menu->option_descriptions.push_back("為您的隊員補充血量至多70%，達到等級3後即可使用，讓您的勇者再次精力充沛!重量2");
	menu->option_descriptions.push_back("將血量恢復至90%、魔力增加原有的20%，等級3即可飲用，讓您的勇者同時獲得充沛精力與更上層樓的魔力！重量3");
	menu->option_descriptions.push_back("");
}

void Store::initializeBackpackMenu()
{
	backpack_screen = new Menu;

	backpack_screen->question_name = "查看您的背包";

	if (backpack->showBackpack().size() != 0) {
		backpack_screen->instruction.push_back("請以↑↓鍵移動游標，並以Esc鍵退出");
		backpack_screen->options = backpack->showBackpack();

		for (int i = 0; i < backpack_screen->options.size(); i++) {
			backpack_screen->option_descriptions.push_back(backpack->showItemInfo(i));
		}
	}
	else {
		backpack_screen->instruction.push_back("您的背包還沒有東西，多放點物資進來吧~~");
		backpack_screen->options.push_back("");
		backpack_screen->option_descriptions.push_back("這裡空空依舊，等待您來充實");
	}
}

Store::Store(Backpack* backpack_ptr, unsigned int* money)
{
	Store::backpack = backpack_ptr;
	Store::money = money;
	initializeStoreMenu();
}

void Store::run()
{
	system("cls");

	int store_menu_selected;
	bool end = false;

	while (1) {
		system("cls");
		//cout << "                                您的錢包餘額：" << *money << "元" << "   背包容量：" << backpack->getCurrentBackpackWeight() << "/" << backpack->getBackpackWeightLimit();
		stringstream ss;
		string backpack_info;
		backpack_info += "您的錢包餘額：";
		ss << *money;
		backpack_info += ss.str(); ss.str(""); ss.clear();
		backpack_info += "元   背包容量：";
		ss << backpack->getCurrentBackpackWeight();
		backpack_info += ss.str(); ss.str(""); ss.clear();
		backpack_info += '/';
		ss << backpack->getBackpackWeightLimit();
		backpack_info += ss.str(); ss.str(""); ss.clear();

		menu->instruction.at(0) = backpack_info;

		store_menu_selected = menu->run();

		switch (store_menu_selected) {
		case 0:
			if (*money < 20) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new SkywardSword;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 20;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 1:
			if (*money < 35) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new DragonKillFalchion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 35;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 2:
			if (*money < 15) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new Armour;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 15;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 3:
			if (*money < 30) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new GoldenShield;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 30;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 4:
			if (*money < 25) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new LifePotion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 25;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 5:
			if (*money < 40) {
				cout << "     錢包君吐不夠錢只好吐血啦QQ\n\n"; Sleep(1000);
			}
			else {
				item = new MagicPotion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     您的背包裝不下了啦啦\n\n"; Sleep(1000);
				}
				else {
					*money -= 40;
					cout << "     購買完成!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 6:
			initializeBackpackMenu();
			system("cls");
			//while (backpack_screen->run() != -1) {}
			backpack->display();
			delete backpack_screen;
			break;
		case -1:
			end = true;
			break;
		}
		if (end) {
			break;
		}
	}
}

Store::~Store()
{
	delete menu;
}
