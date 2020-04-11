#include "NovicePlayer.h"
#include <cmath>

NovicePlayer::NovicePlayer()
{
	name = "anonymous";
	setLevel(1);
	hp = 0;
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int lv)
{
	name = "anonymous";
	setLevel(lv);
	hp = 0;
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int lv, string n)
{
	name = n;
	setLevel(lv);
	hp = 0;
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(const NovicePlayer& a)
{
	name = a.name;
	hp = a.hp;
	mp = a.mp;
	exp = a.exp;
	money = a.money;
	level = a.level;
	attack = a.attack;
	defense = a.defense;
	max_hp = a.max_hp;
	max_mp = a.max_mp;
	lvup_exp = a.lvup_exp;
}

void NovicePlayer::setName(string n)
{
	name = n;
}

string NovicePlayer::getName() const
{
	return name;
}

void NovicePlayer::setLevel(int value)
{
	if (value >= 1) {
		level = value;
	}
	else {
		level = 1;
	}
	attack = 20 + 5 * level;
	defense = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	max_mp = 40 + 5 * level;
	lvup_exp = pow(10, log2(level + 1));
}

int NovicePlayer::getLevel() const
{
	return level;
}

void NovicePlayer::setHp(int value)
{
	if (value < 0) {
		hp = 0;
	}
	else if (value > max_hp) {
		hp = max_hp;
	}
	else {
		hp = value;
	}
}

int NovicePlayer::getHp() const
{
	return hp;
}

void NovicePlayer::setMp(int value)
{
	if (value < 0) {
		mp = 0;
	}
	else if (value > max_mp) {
		mp = max_mp;
	}
	else {
		mp = value;
	}
}

int NovicePlayer::getMp() const
{
	return mp;
}

void NovicePlayer::setExp(int value)
{
	if (value <= 0) {
		return;
	}
	else if (value > lvup_exp) {
		exp = lvup_exp;
	}
	else {
		exp = value;
	}
}

int NovicePlayer::getExp() const
{
	return exp;
}

void NovicePlayer::setMoney(int value)
{
	if (value < 0) {
		money = 0;
	}
	else {
		money = value;
	}
}

int NovicePlayer::getMoney() const
{
	return money;
}

int NovicePlayer::getAttack(void) const
{
	return attack;
}

int NovicePlayer::getDefense(void) const
{
	return defense;
}

int NovicePlayer::getMaxHP(void) const
{
	return max_hp;
}

int NovicePlayer::getMaxMP(void) const
{
	return max_mp;
}

int NovicePlayer::getLvupExp(void) const
{
	return lvup_exp;
}

