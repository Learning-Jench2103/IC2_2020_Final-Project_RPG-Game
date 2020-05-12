#ifndef CONSUMABLE_LIFEPOTION_H
#define CONSUMABLE_LIFEPOTION_H

#include "ConsumableItem.h"

class NovicePlayer;

class LifePotion : public ConsumableItem
{
	LifePotion();
	virtual void use(NovicePlayer* player);

	/*
	required_level = 3;
	name = "生命藥水";
	effects = "補充血量至7成";
	description = "達到等級3後即可使用，讓您的勇者再次精力充沛!";
	weight = 2;
	type = 'c';
	need_hands = -1;
	*/

};

#endif