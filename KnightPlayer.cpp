#include "KnightPlayer.h"

KnightPlayer::KnightPlayer()
	:NovicePlayer()
{
	setLevel(1);	// default level = 1
}

KnightPlayer::KnightPlayer(int value)
	: NovicePlayer(value)
{
	setLevel(value);	// KnightPlayer::setLevel(int)
}

KnightPlayer::KnightPlayer(int value, string n)
	: NovicePlayer(value, n)
{
	setLevel(value);	// KnightPlayer::setLevel(int)
}

KnightPlayer::KnightPlayer(const KnightPlayer& a)
	: NovicePlayer(a)	// the copy constructor of NovicePlayer will copy every data, so don't need to call setLevel() again
{
}

void KnightPlayer::setLevel(int value)
{
	if (value < 1) {
		level = 1;
	}
	else {
		level = value;
	}
	max_hp = 150 + 25 * level;
	max_mp = 70 + 10 * level;
	attack = 40 + 10 * level;
	defense = 20 + 12 * level;
	lvup_exp = pow(10, log2(level + 1));
}

void KnightPlayer::heal(NovicePlayer& a)	// the argument allow objects of all derived classes of NovicePlayer
{
	setMp(getMp() - level * 5);
	a.setHp(a.getHp() + level * 10);
}
