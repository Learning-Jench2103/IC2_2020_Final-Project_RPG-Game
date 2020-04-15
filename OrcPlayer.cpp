#include "OrcPlayer.h"

OrcPlayer::OrcPlayer()
	:NovicePlayer()
{
	setLevel(1);	// OrcPlayer::setLevel(int value)
}

OrcPlayer::OrcPlayer(int value)
	: NovicePlayer(value)
{
	setLevel(value);	// OrcPlayer::setLevel(int value)
}

OrcPlayer::OrcPlayer(int value, string n)
	: NovicePlayer(value, n)
{
	setLevel(value);	// OrcPlayer::setLevel(int value)
}

OrcPlayer::OrcPlayer(const OrcPlayer& a)
	: NovicePlayer(a)
{
	setLevel(a.level);
	attack = a.attack;
	defense = a.defense;
	max_hp = a.max_hp;
	max_mp = a.max_mp;
	lvup_exp = a.lvup_exp;
	setHp(a.getHp());
	setMp(a.getMp());
	setExp(a.getExp());
	setMoney(a.getMoney());
}

void OrcPlayer::setLevel(int value)
{
	if (value < 1) {
		level = 1;
	}
	else {
		level = value;
	}
	max_hp = 200 + 20 * level;
	max_mp = 50 + 5 * level;
	attack = 50 + 12 * level;
	defense = 30 + 10 * level;
	lvup_exp = pow(10, log2(level + 1));
}
