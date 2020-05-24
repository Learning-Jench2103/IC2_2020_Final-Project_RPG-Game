#include "Consumable_MagicPotion.h"
#include "../Players/NovicePlayer.h"

MagicPotion::MagicPotion()
	:ConsumableItem(3, "�]�k�Ĥ�", "�N��q��_��90%�B�]�O�W�[�즳��20%", "����3�Y�i��o�A���z���i�̦P����o�R�K��O�P��W�@�h�Ӫ��]�O�I", 3)
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
