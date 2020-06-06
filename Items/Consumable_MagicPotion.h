#ifndef CONSUMABLE_MAGICPOTION_H
#define CONSUMABLE_MAGICPOTION
#include "./base/ConsumableItem.h"

class NovicePlayer;

class MagicPotion : public ConsumableItem
{
public:
	MagicPotion();
	virtual void use(NovicePlayer*);
	virtual string getEngName();
};

#endif