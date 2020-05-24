#include "GoblinMonster.h"
#include <sstream>
using namespace std;

GoblinMonster::GoblinMonster()
	:BaseMonster("Goblin", 60, 40, 12, 30, 100, 50)
{
}

GoblinMonster::GoblinMonster(string n)
	: BaseMonster(n, 60, 40, 12, 30, 100, 50)
{
}

GoblinMonster::GoblinMonster(string n, int att, int def, int ex, int mon, int mH, int mP)
	: BaseMonster(n, att, def, ex, mon, mH, mP)
{
}

GoblinMonster::GoblinMonster(GoblinMonster& a)
	: BaseMonster(a)
{
}

string GoblinMonster::serialize()
{
	stringstream ss;
	string record;

	record += "#GoblinMonster$";
	// name //
	record += name;
	record += '$';
	// attack //
	ss << attack;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// defense //
	ss << defense;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// exp //
	ss << exp;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// money //
	ss << money;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// max_hp //
	ss << max_hp;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// max_mp //
	ss << max_mp;
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// hp //
	ss << getHP();
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '$';
	// mp //
	ss << getMP();
	record += ss.str();
	ss.str("");
	ss.clear();
	record += '@';	// end signal

	return record;
}

BaseMonster* GoblinMonster::unserialize(string record)
{
	stringstream ss;
	size_t start, end;
	start = record.find('#');
	end = record.find('$', start + 1);
	// check class name //
	if (string(record, start + 1, end - start - 1) != "GoblinMonster") {
		return nullptr;
	}

	string n;
	int att, def, ex, mon, mH, mP, h, m;
	// name //
	start = end;
	end = record.find('$', start + 1);
	n = string(record, start + 1, end - start - 1);
	// attack //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> att;
	ss.str("");
	ss.clear();
	// defense //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> def;
	ss.str("");
	ss.clear();
	// exp //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> ex;
	ss.str("");
	ss.clear();
	// money //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> mon;
	ss.str("");
	ss.clear();
	// max_hp //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> mH;
	ss.str("");
	ss.clear();
	// max_mp //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> mP;
	ss.str("");
	ss.clear();
	// hp //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> h;
	ss.str("");
	ss.clear();
	// mp //
	start = end;
	end = record.find('$', start + 1);
	ss << string(record, start + 1, end - start - 1);
	ss >> m;
	ss.str("");
	ss.clear();

	// construct object //
	GoblinMonster* a = new GoblinMonster(n, att, def, ex, mon, mH, mP);
	a->setHP(h);
	a->setMP(m);

	return a;
}
