#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H
#include "Item.h"

class NovicePlayer;

class ConsumableItem :public Item {
public:
	ConsumableItem(int level_required, string name, string effects, string description, int weight, char type, int need_hands, int hp_increment, int mp_increment, int exp_increment)
		:Item(level_required, name, effects, description, weight, type, need_hands)
	{
	}

	virtual void use(NovicePlayer*) = 0;

protected:
	bool used = false;

};

#endif