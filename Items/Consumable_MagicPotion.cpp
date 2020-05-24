#include "Consumable_MagicPotion.h"
#include "../Players/NovicePlayer.h"

MagicPotion::MagicPotion()
	:ConsumableItem(3, "魔法藥水", "將血量恢復至90%、魔力增加原有的20%", "等級3即可獲得，讓您的勇者同時獲得充沛精力與更上一層樓的魔力！", 3)
{
}

void MagicPotion::use(NovicePlayer* player)
{
	if (used) {
		return;
	}
	if (player->getLevel() < 3) {
		return;
	}
	if (player->getHp() < player->getMaxHP() * 0.9) {
		player->setHp(player->getMaxHP() * 0.9);
	}
	player->setMp(player->getMp() * 1.2);

	used = true;
}
