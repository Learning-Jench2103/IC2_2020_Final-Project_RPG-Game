#ifndef CONSUMABLE_MAGICPOTION_H
#define CONSUMABLE_MAGICPOTION
#include "ConsumableItem.h"

class NovicePlayer;

class MagicPotion : public ConsumableItem
{
public:
	MagicPotion();
	virtual void use(NovicePlayer*);
};

#endif