#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <string>
#include "Backpack.h"
#include "Menu.h"
#include "../Items/base/Item.h"
#include "../Items/Armor_Armour.h"
#include "../Items/Armor_GoldenShield.h"
#include "../Items/Consumable_LifePotion.h"
#include "../Items/Consumable_MagicPotion.h"
#include "../Items/Weapon_DragonKillFalchion.h"
#include "../Items/Weapon_SkywardSword.h"

using namespace std;

class Store {
private:
	Menu* menu;
	Backpack* backpack;
	Menu* backpack_screen;
	unsigned int* money;
	void initializeStoreMenu();
	void initializeBackpackMenu();

	Item* item;


public:
	Store(Backpack* backpack_ptr, unsigned int* money);
	void run();
	~Store();

};

#endif