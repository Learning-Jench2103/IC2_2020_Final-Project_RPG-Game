#include "KnightPlayer.h"
#include <string>
#include <sstream>

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

void KnightPlayer::specialSkill(void)
{
	if (getMp() < 10) {
		return;
	}
	setMp(getMp() - 10);
	setHp(getHp() + 15);
}

string KnightPlayer::serialize()
{
	stringstream ss;
	string result;
	result += "@KnightPlayer$";
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

NovicePlayer* KnightPlayer::unserialize(string record)
{
	size_t begin, end;
	stringstream ss;
	begin = record.find('@');
	end = record.find('$', begin);
	// check class name //
	if (string(record, begin + 1, end - begin - 1) != "KnightPlayer") {
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
	KnightPlayer* a = new KnightPlayer(lev, n);
	a->setHp(h);
	a->setMp(m);
	a->setExp(ex);
	a->setMoney(mon);

	return a;
}

