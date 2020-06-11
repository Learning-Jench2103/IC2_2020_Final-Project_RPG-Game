#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H
#include "Item.h"

class NovicePlayer;

class ConsumableItem :public Item {
public:
	ConsumableItem(int level_required, string name, string effects, string description, int weight)
		:Item(level_required, name, effects, description, weight, 'c', -1)
	{
	}

	virtual void use(NovicePlayer*) = 0;

protected:
	bool used = false;

};

#endif