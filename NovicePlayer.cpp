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
	setLevel(a.level);
	setHp(round((double)a.hp / a.max_hp * max_hp));
	setMp(round((double)a.mp / a.max_mp * max_mp));
	exp = round((double)a.exp / a.lvup_exp * lvup_exp);	// setExp() do not allow 0 as argument, so here we should assign the value directly so that a origin class whose exp is 0 can by copy, too.
	setMoney(a.money);
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

ostream& operator<<(ostream& output, const NovicePlayer& a)
{
	output << "=========== Player Information ===========" << endl;
	output << "Player name = " << a.name << endl;
	output << "Level = " << a.level << endl;
	output << "Attack = " << a.attack << endl;
	output << "Defense = " << a.defense << endl;
	output << "max_hp = " << a.max_hp << endl;
	output << "max_mp = " << a.max_mp << endl;
	output << "lvup_exp = " << a.lvup_exp << endl;
	output << "hp = " << a.hp << endl;
	output << "mp = " << a.mp << endl;
	output << "exp = " << a.exp << endl;
	output << "money = " << a.money << endl;
	output << "==========================================" << endl;
	return output;
}
