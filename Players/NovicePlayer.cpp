#include "NovicePlayer.h"
#include "../Items/base/Item.h"
#include "../Items/base/WeaponItem.h"
#include "../Items/base/ArmorItem.h"
#include "../Items/base/ConsumableItem.h"
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
	//money = 0;
}

NovicePlayer::NovicePlayer(int lv)
{
	name = "anonymous";
	setLevel(lv);
	hp = max_hp;
	mp = max_mp;
	exp = 0;
	//money = 0;
}

NovicePlayer::NovicePlayer(int lv, string n)
{
	name = n;
	setLevel(lv);
	hp = max_hp;
	mp = max_mp;
	exp = 0;
	//money = 0;
}

NovicePlayer::NovicePlayer(const NovicePlayer& a)
{
	name = a.name;
	setLevel(a.level);
	setHp(round((double)a.hp / a.max_hp * max_hp));
	setMp(round((double)a.mp / a.max_mp * max_mp));
	exp = round((double)a.exp / a.lvup_exp * lvup_exp);	// setExp() do not allow 0 as argument, so here we should assign the value directly so that a origin class whose exp is 0 can by copy, too.
	//setMoney(a.money);
}

NovicePlayer::~NovicePlayer()
{
	if (weapon != nullptr) {
		delete weapon;
	}
	if (armor != nullptr) {
		delete armor;
	}
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
	hp = max_hp;
	mp = max_mp;
	lvup_exp = pow(10, log2(level + 1));

	//backpack.setWeightLimit(70 + 30 * level);
}

int NovicePlayer::getLevel() const
{
	return level;
}

void NovicePlayer::addHp(int value)
{
	setHp(hp + value);
}

void NovicePlayer::decreaseHp(int value)
{
	hp -= value * 0.5;
	if (hp < 0) {
		hp = 0;
	}
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

void NovicePlayer::minusExp(int value)
{
	setExp(getExp() - value);
}

int NovicePlayer::getExp() const
{
	return exp;
}

/*
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
*/
void NovicePlayer::setAttack(int attack)
{
	NovicePlayer::attack = attack;
}

int NovicePlayer::getAttack(void) const
{
	return attack;
}

void NovicePlayer::setDefense(int defense)
{
	NovicePlayer::defense = defense;
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

string NovicePlayer::showInfo()
{
	string result;
	stringstream ss;
	result += "職業：NovicePlayer  ";
	result += " 名字：" + name;
	result += " 等級："; ss << level;	result += ss.str();	ss.str("");	ss.clear();
	result += " 經驗："; ss << exp;	result += ss.str();	ss.str("");	ss.clear();
	result += " 血量："; ss << hp;	result += ss.str();	ss.str("");	ss.clear();
	result += " 魔力："; ss << mp;	result += ss.str();	ss.str("");	ss.clear();
	result += " 攻擊力："; ss << attack;	result += ss.str();	ss.str("");	ss.clear();
	result += " 防禦力："; ss << defense;	result += ss.str();	ss.str("");	ss.clear();
	result += " 升級所需經驗值："; ss << lvup_exp;	result += ss.str();	ss.str("");	ss.clear();
	if (weapon != NULL) {
		result += " 裝備武器：" + weapon->name;
	}
	if (armor != NULL) {
		result += " 裝備防護：" + armor->name;
	}

	return result;
}

WeaponItem* NovicePlayer::getWeapon()
{
	return weapon;
}

ArmorItem* NovicePlayer::getArmor()
{
	return armor;
}

void NovicePlayer::specialSkill(void)
{

}

bool NovicePlayer::equipWeapon(WeaponItem* weapon, Backpack* backpack)
{
	if (armor != nullptr && armor->need_hands + weapon->need_hands > 2) {
		return false;
	}
	if (weapon->level_required > getLevel()) {
		return false;
	}
	if (NovicePlayer::weapon != nullptr) {
		setAttack(getAttack() - NovicePlayer::weapon->attack_increment);
		backpack->putItem(NovicePlayer::weapon);
	}
	NovicePlayer::weapon = weapon;
	setAttack(getAttack() + weapon->attack_increment);
	return true;
}

bool NovicePlayer::equipArmor(ArmorItem* armor, Backpack* backpack)
{
	if (weapon != nullptr && armor->need_hands + weapon->need_hands > 2) {
		return false;
	}
	if (NovicePlayer::armor != nullptr) {
		setDefense(getDefense() - NovicePlayer::armor->defense_increment);
		backpack->putItem(NovicePlayer::armor);
	}
	NovicePlayer::armor = armor;
	setDefense(getDefense() + armor->defense_increment);
	return true;
}

void NovicePlayer::useConsumable(ConsumableItem* consumable)
{
	consumable->use(this);
}

vector<string> NovicePlayer::getInfoArray() const
{
	vector<string> infoArray;
	stringstream ss;
	/*
	output << "=========== Player Information ===========" << endl;
	// output << "Player name = " << a.name << endl;
	// output << "Level = " << a.level << endl;
	// output << "Attack = " << a.attack << endl;
	// output << "Defense = " << a.defense << endl;
	// output << "max_hp = " << a.max_hp << endl;
	// output << "max_mp = " << a.max_mp << endl;
	output << "lvup_exp = " << a.lvup_exp << endl;
	// output << "hp = " << a.hp << endl;
	// output << "mp = " << a.mp << endl;
	// output << "exp = " << a.exp << endl;
	// output << "money = " << a.money << endl;
	output << "==========================================" << endl;
	*/
	infoArray.push_back("=========== Player Information ===========");
	infoArray.push_back("名字：" + getName());
	infoArray.push_back("職業：NovicePlayer");
	ss << getLevel(); infoArray.push_back("等級：" + ss.str()); ss.str(""); ss.clear();
	ss << getHp(); infoArray.push_back("血量：" + ss.str()); ss.str(""); ss.clear();
	ss << getMp(); infoArray.push_back("魔力：" + ss.str()); ss.str(""); ss.clear();
	ss << getAttack(); infoArray.push_back("攻擊力：" + ss.str()); ss.str(""); ss.clear();
	ss << getDefense(); infoArray.push_back("防禦力：" + ss.str()); ss.str(""); ss.clear();
	ss << getExp(); infoArray.push_back("經驗值：" + ss.str()); ss.str(""); ss.clear();
	ss << getMaxHP(); infoArray.push_back("最大血量：" + ss.str()); ss.str(""); ss.clear();
	ss << getMaxMP(); infoArray.push_back("最大魔力：" + ss.str()); ss.str(""); ss.clear();
	ss << getLvupExp(); infoArray.push_back("下一等級經驗值：" + ss.str()); ss.str(""); ss.clear();
	infoArray.push_back("==========================================");
	return infoArray;
}

/*
int NovicePlayer::getCurrentBackpackWeight(void) const
{
	return backpack.getCurrentBackpackWeight();
}

int NovicePlayer::getBackpackWeightLimit(void) const
{
	return backpack.getBackpackWeightLimit();
}


vector<string> NovicePlayer::showBackpack(void) const
{
	return backpack.showBackpack();
}

vector<string> NovicePlayer::showItemInfo(int index) const
{
	return backpack.showItemInfo(index);
}

int NovicePlayer::getItemAmount(void) const
{
	return backpack.getItemAmount();
}

Item* NovicePlayer::getItemPtr(int index)
{
	return backpack.takeItem(index);
}

bool NovicePlayer::putItem(Item* item)
{
	return backpack.putItem(item);
}
*/

string NovicePlayer::serialize()
{
	string result;
	stringstream ss;
	vector<int*> from = { &hp, &mp, &exp,  &level };
	result += "@NovicePlayer$";
	result += name;
	for (int i = 0; i < 4; i++) {
		result += '$';
		ss << *(from[i]);
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
	int h, m, ex, lev;
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
	/*
	// money //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> mon;
	ss.str("");
	ss.clear();
	*/
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
	//a->setMoney(mon);

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
	//output << "money = " << a.money << endl;
	output << "==========================================" << endl;
	return output;
}
