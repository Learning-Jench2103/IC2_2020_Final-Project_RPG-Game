#ifndef ARMORITEM_H
#define ARMORITEM_H
#include "Item.h"

class ArmorItem :public Item {
public:
	const int defense_increment;

	ArmorItem(int level_required, string name, string effects, string description, int weight, char type, int need_hands, int defense_increment, int exp_increment)
		:Item(level_required, name, effects, description, weight, type, need_hands),
		defense_increment(defense_increment)
	{
	}


};



#endif