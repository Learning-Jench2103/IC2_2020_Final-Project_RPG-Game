#include "NovicePlayer.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

NovicePlayer::NovicePlayer()
{
	name = "anonymous";
	setLevel(1);
	hp = max_hp;
	mp = max_mp;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int lv)
{
	name = "anonymous";
	setLevel(lv);
	hp = max_hp;
	mp = max_mp;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int lv, string n)
{
	name = n;
	setLevel(lv);
	hp = max_hp;
	mp = max_mp;
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
		setLevel(level + 1);
		setExp(value);
	}
	else {
		exp = value;
	}
}

void NovicePlayer::addExp(int a)
{
	setExp(getExp() + a);
}

void NovicePlayer::addExp(double ratio)
{
	setExp(getExp() + lvup_exp * (ratio));
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

void NovicePlayer::addMoney(int a)
{
	setMoney(getMoney() + a);
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

void NovicePlayer::specialSkill(void)
{

}

string NovicePlayer::serialize()
{
	string result;
	stringstream ss;
	vector<int*> from = { &hp, &mp, &exp, &money, &level };
	result += "@NovicePlayer$";
	result += name;
	for (int i = 0; i < 5; i++) {
		result += '$';
		ss << *from[i];
		result += ss.str();
		ss.str("");
		ss.clear();
	}
	result += '#';	// end signal
	return result;
}

NovicePlayer* NovicePlayer::unserialize(string record)
{
	size_t begin, end;
	stringstream ss;
	begin = record.find('@');
	end = record.find('$', begin);
	// check class name //
	if (string(record, begin + 1, end - begin - 1) != "NovicePlayer") {
		return nullptr;
	}

	string n;
	int h, m, ex, mon, lev;
	// name //
	begin = end;
	end = record.find('$', begin + 1);
	n = string(record, begin + 1, end - begin - 1);
	// hp //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> h;
	ss.str("");
	ss.clear();
	// mp //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> m;
	ss.str("");
	ss.clear();
	// exp //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> ex;
	ss.str("");
	ss.clear();
	// money //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> mon;
	ss.str("");
	ss.clear();
	// level //
	begin = end;
	end = record.find('#', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> lev;
	ss.str("");
	ss.clear();

	// construct object //
	NovicePlayer* a = new NovicePlayer(lev, n);
	a->setHp(h);
	a->setMp(m);
	a->setExp(ex);
	a->setMoney(mon);

	return a;
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
