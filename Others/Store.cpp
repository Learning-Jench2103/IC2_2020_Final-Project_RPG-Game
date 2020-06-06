#include "Store.h"
#include <Windows.h>
#include <sstream>
using namespace std;

void Store::initializeStoreMenu()
{
	menu = new Menu;

	menu->question_name = "�ө���";
	menu->instruction.push_back("");
	menu->instruction.push_back("");
	menu->instruction.push_back("�ХH�����䲾�ʴ�Цܱ��ʶR���~���A���UEnter�ʶR");
	menu->instruction.push_back("�ʶR�e�Ъ`�N�C�ӥΫ~�����ŭ���A�u������F��ӵ��Ū������~��ϥή@");
	menu->instruction.push_back("�������椽�D���|�����O�̡A�Цw�߿���!!");
	menu->instruction.push_back("�����z�A�ڭ̤����Ѱh�f�A�ȡA�ӫ~�@�g��X�L�k����~~");

	menu->options.push_back("�� �� �C--���20��");
	menu->options.push_back("�O �s �M--���35��");
	menu->options.push_back("���@�@��--���15��");
	menu->options.push_back("�� �� �n--���30��");
	menu->options.push_back("�ͩR����--���25��");
	menu->options.push_back("�]�k�Ĥ�--���40��");
	menu->options.push_back("�d�ݱz���I�]");

	menu->option_descriptions.push_back("�����O�W�j10�I�A���z����ĤH�ɧ��¯١C����2�H�W�i�t�ơA���q20�A�H���ϥ�");
	menu->option_descriptions.push_back("�����O�W�[25�I�A���z����j�ĵL�Ҭ��ߡC����4�H�W��i�t�ơA���q30�A�H����ϥ�");
	menu->option_descriptions.push_back("�˳ƫ�i�W�[5�I���m�O�C����2�H�W�i�˳ơA���q15");
	menu->option_descriptions.push_back("�˳ƫ�i�W�[10�I���m�O�A���z�����ɵL���U���~�C����4�H�W�i�ϥΡA���q20");
	menu->option_descriptions.push_back("���z�������ɥR��q�ܦh70%�A�F�쵥��3��Y�i�ϥΡA���z���i�̦A����O�R�K!���q2");
	menu->option_descriptions.push_back("�N��q��_��90%�B�]�O�W�[�즳��20%�A����3�Y�i���ΡA���z���i�̦P����o�R�K��O�P��W�h�Ӫ��]�O�I���q3");
	menu->option_descriptions.push_back("");
}

void Store::initializeBackpackMenu()
{
	backpack_screen = new Menu;

	backpack_screen->question_name = "�d�ݱz���I�]";

	if (backpack->showBackpack().size() != 0) {
		backpack_screen->instruction.push_back("�ХH�����䲾�ʴ�СA�åHEsc��h�X");
		backpack_screen->options = backpack->showBackpack();

		for (int i = 0; i < backpack_screen->options.size(); i++) {
			backpack_screen->option_descriptions.push_back(backpack->showItemInfo(i));
		}
	}
	else {
		backpack_screen->instruction.push_back("�z���I�]�٨S���F��A�h���I����i�ӧa~~");
		backpack_screen->options.push_back("");
		backpack_screen->option_descriptions.push_back("�o�̪ŪŨ��¡A���ݱz�ӥR��");
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
		//cout << "                                �z�����]�l�B�G" << *money << "��" << "   �I�]�e�q�G" << backpack->getCurrentBackpackWeight() << "/" << backpack->getBackpackWeightLimit();
		stringstream ss;
		string backpack_info;
		backpack_info += "�z�����]�l�B�G";
		ss << *money;
		backpack_info += ss.str(); ss.str(""); ss.clear();
		backpack_info += "��   �I�]�e�q�G";
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
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new SkywardSword;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 20;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 1:
			if (*money < 35) {
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new DragonKillFalchion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 35;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 2:
			if (*money < 15) {
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new Armour;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 15;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 3:
			if (*money < 30) {
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new GoldenShield;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 30;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 4:
			if (*money < 25) {
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new LifePotion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 25;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
				}
			}
			break;
		case 5:
			if (*money < 40) {
				cout << "     ���]�g�R�������u�n�R���QQ\n\n"; Sleep(1000);
			}
			else {
				item = new MagicPotion;
				if (!backpack->putItem(item)) {
					delete item;
					cout << "     �z���I�]�ˤ��U�F�հ�\n\n"; Sleep(1000);
				}
				else {
					*money -= 40;
					cout << "     �ʶR����!!\n\n"; Sleep(1000);
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
