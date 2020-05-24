#ifndef WEAPONITEM_H
#define WEAPONITEM_H
#include "Item.h"

class WeaponItem :public Item {
public:
	const int attack_increment;

	WeaponItem(int level_required, string name, string effects, string description, int weight, char type, int need_hands, int attack_increment, int exp_increment)
		:Item(level_required, name, effects, description, weight, type, need_hands),
		attack_increment(attack_increment)
	{
	}

};



#endif