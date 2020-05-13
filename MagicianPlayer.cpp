#include "MagicianPlayer.h"
#include <string>
#include <sstream>

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

void MagicianPlayer::specialSkill(void)
{
	if (getHp() < 15) {
		return;
	}
	setMp(getMp() + 10);
	setHp(getHp() - 15);
}

string MagicianPlayer::serialize()
{
	stringstream ss;
	string result;
	result += "@MagicianPlayer$";
	// name //
	result += getName();
	result += '$';
	// hp //
	ss << getHp();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';
	// mp //
	ss << getMp();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';
	// exp //
	ss << getExp();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';
	// money //
	ss << getMoney();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';
	// level //
	ss << getLevel();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '#';	// end signal

	return result;
}

NovicePlayer* MagicianPlayer::unserialize(string record)
{
	size_t begin, end;
	stringstream ss;
	begin = record.find('@');
	end = record.find('$', begin);
	// check class name //
	if (string(record, begin + 1, end - begin - 1) != "MagicianPlayer") {
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
	MagicianPlayer* a = new MagicianPlayer(lev, n);
	a->setHp(h);
	a->setMp(m);
	a->setExp(ex);
	a->setMoney(mon);

	return a;
}

