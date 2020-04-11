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
	: NovicePlayer(a)	// the copy constructor of NovicePlayer will copy every data, so don't need to call setLevel() again
{
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
