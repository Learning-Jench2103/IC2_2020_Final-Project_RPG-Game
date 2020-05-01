#include "BaseMonster.h"

int BaseMonster::count = 0;

BaseMonster::BaseMonster(string n, int att, int def, int ex, int mon, int mH, int mP) :
	name(n), attack(att), defense(def), exp(ex), money(mon), max_hp(mH), max_mp(mP)
{
	hp = 0;
	mp = 0;
	++count;
}

BaseMonster::BaseMonster(BaseMonster& a)
	:name(a.name),attack(a.attack),defense(a.defense),exp(a.exp),money(a.money),max_hp(a.max_hp),max_mp(a.max_mp)
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
	else if(h > max_hp){
		hp = max_hp;
	}
	else {
		hp = h;
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
	output << "money = " << a.money << endl;
	output << "max_hp = " << a.max_hp << endl;
	output << "max_mp = " << a.max_mp << endl;
	output << "hp = " << a.hp << endl;
	output << "mp = " << a.mp << endl;
	output << "==========================================" << endl;
	return output;
}
