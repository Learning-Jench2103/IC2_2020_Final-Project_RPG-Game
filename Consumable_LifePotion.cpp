#include "Consumable_LifePotion.h"
#include "NovicePlayer.h"

LifePotion::LifePotion()
	:ConsumableItem(3, "LifePotion", "�ɥR��q��7��", "�F�쵥��3��Y�i�ϥΡA���z���i�̦A����O�R�K!", 2)
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
