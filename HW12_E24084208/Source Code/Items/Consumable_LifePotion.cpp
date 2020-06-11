#include "Consumable_LifePotion.h"
#include "..\Players\NovicePlayer.h"

LifePotion::LifePotion()
	:ConsumableItem(3, "生命之水", "補充血量至7成", "達到等級3後即可使用，讓您的勇者再次精力充沛!", 2)
{
}

void LifePotion::use(NovicePlayer* player)
{
	if (used) {
		return;
	}
	if (player->getHp() < player->getMaxHP() * 0.7) {
		player->setHp(player->getMaxHP() * 0.7);
	}
	used = true;
}

string LifePotion::getEngName()
{
	return "LifePotion";
}
