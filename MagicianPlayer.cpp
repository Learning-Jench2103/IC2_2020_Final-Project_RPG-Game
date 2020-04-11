#include "MagicianPlayer.h"

MagicianPlayer::MagicianPlayer()
	:NovicePlayer()
{
	setLevel(1);	// MagicianPlayer::setLevel(int value)
}

MagicianPlayer::MagicianPlayer(int value)
	: NovicePlayer(value)
{
	setLevel(value);	// MagicianPlayer::setLevel(int value)
}

MagicianPlayer::MagicianPlayer(int value, string n)
	: NovicePlayer(value, n)
{
	setLevel(value);	// MagicianPlayer::setLevel(int value)
}

MagicianPlayer::MagicianPlayer(const MagicianPlayer& a)
	: NovicePlayer(a)	// the copy constructor of NovicePlayer will copy every data, so don't need to call setLevel() again
{
}

void MagicianPlayer::setLevel(int value)
{
	if (value < 1) {
		level = 1;
	}
	else {
		level = value;
	}
	max_hp = 120 + 15 * level;
	max_mp = 100 + 15 * level;
	attack = 30 + 8 * level;
	defense = 20 + 7 * level;
	lvup_exp = pow(10, log2(level + 1));
}

void MagicianPlayer::pray(NovicePlayer& a)	// the argument allow objects of all derived classes of NovicePlayer
{
	a.setMp(getMp() + level * 10);
	a.setHp(getHp() - level * 5);
}
