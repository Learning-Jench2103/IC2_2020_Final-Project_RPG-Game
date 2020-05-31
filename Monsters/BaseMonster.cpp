#include "BaseMonster.h"
#include <sstream>

int BaseMonster::count = 0;

BaseMonster::BaseMonster(string n, int att, int def, int ex, int mon, int mH, int mP) :
	name(n), attack(att), defense(def), exp(ex), money(mon), max_hp(mH), max_mp(mP)
{
	hp = max_hp;
	mp = max_mp;
	++count;
}

BaseMonster::BaseMonster(BaseMonster& a)
	:name(a.name), attack(a.attack), defense(a.defense), exp(a.exp), money(a.money), max_hp(a.max_hp), max_mp(a.max_mp)
{
	hp = a.hp;
	mp = a.mp;
	++count;
}

BaseMonster::~BaseMonster()
{
	--count;
}

void BaseMonster::setHP(int h)
{
	if (h < 0) {
		hp = 0;
	}
	else if (h > max_hp) {
		hp = max_hp;
	}
	else {
		hp = h;
	}
}

void BaseMonster::decreaseHp(int value)
{
	hp -= value;
	if (hp < 0) {
		hp = 0;
	}
}

int BaseMonster::getHP() const
{
	return hp;
}

void BaseMonster::setMP(int m)
{
	if (m < 0) {
		mp = 0;
	}
	else if (m > max_mp) {
		mp = max_mp;
	}
	else {
		mp = m;
	}
}

int BaseMonster::getMP() const
{
	return mp;
}

vector<string> BaseMonster::getInfo() const
{
	vector<string> info;
	stringstream ss;

	info.push_back("=========== Monster Information ===========");
	info.push_back("名字 = " + name);
	ss << attack; info.push_back("攻擊 = " + ss.str()); ss.str(""); ss.clear();
	ss << defense; info.push_back("防禦 = " + ss.str()); ss.str(""); ss.clear();
	ss << hp; info.push_back("血量：" + ss.str()); ss.str(""); ss.clear();
	//ss << mp; info.push_back("魔力：" + ss.str()); ss.str(""); ss.clear();
	ss << exp; info.push_back("增加的經驗值 = " + ss.str()); ss.str(""); ss.clear();
	ss << max_hp; info.push_back("最大血量 = " + ss.str()); ss.str(""); ss.clear();
	//ss << max_mp; info.push_back("最大魔力 = " + ss.str()); ss.str(""); ss.clear();
	info.push_back("==========================================");
	return info;
}

int BaseMonster::getInstanceCount(void)
{
	return count;
}

ostream& operator<<(ostream& output, const BaseMonster& a)
{
	output << "=========== Monster Information ===========" << endl;
	output << "Monster name = " << a.name << endl;
	output << "Attack = " << a.attack << endl;
	output << "Defense = " << a.defense << endl;
	output << "exp = " << a.exp << endl;
	//output << "money = " << a.money << endl;
	output << "max_hp = " << a.max_hp << endl;
	//output << "max_mp = " << a.max_mp << endl;
	output << "hp = " << a.hp << endl;
	//output << "mp = " << a.mp << endl;
	output << "==========================================" << endl;
	return output;
}
