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
	name = "�ͩR�Ĥ�";
	effects = "�ɥR��q��7��";
	description = "�F�쵥��3��Y�i�ϥΡA���z���i�̦A����O�R�K!";
	weight = 2;
	type = 'c';
	need_hands = -1;
	*/

};

#endif