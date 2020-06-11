#include "MagicianPlayer.h"
#include "../Items/base/ArmorItem.h"
#include "../Items/base/WeaponItem.h"
#include "../Items/Armor_Armour.h"
#include "../Items/Armor_GoldenShield.h"
#include "../Items/Consumable_LifePotion.h"
#include "../Items/Consumable_MagicPotion.h"
#include "../Items/Weapon_DragonKillFalchion.h"
#include "../Items/Weapon_SkywardSword.h"
#include <string>
#include <sstream>

MagicianPlayer::MagicianPlayer()
	:NovicePlayer()
{
	setLevel(1);	// MagicianPlayer::setLevel(int value)
	setHp(max_hp);
	setMp(max_mp);
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
	//setMoney(a.getMoney());
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
	NovicePlayer::setHp(max_hp);
	NovicePlayer::setMp(max_mp);
	attack = 40 + 8 * level;
	defense = 20 + 7 * level;
	lvup_exp = pow(10, log2(level + 1));
}

void MagicianPlayer::setExp(int value)
{
	if (value <= 0) {
		return;
	}
	else if (value > lvup_exp) {
		setLevel(level + 1);
		NovicePlayer::setExp(value);
	}
	else {
		NovicePlayer::setExp(value);
	}
}

void MagicianPlayer::addExp(int a)
{
	setExp(getExp() + a);
}

void MagicianPlayer::addExp(double ratio)
{
	setExp(getExp() + lvup_exp * (ratio));
}

void MagicianPlayer::minusExp(int value)
{
	setExp(getExp() - value);
}

void MagicianPlayer::specialSkill(void)
{
	if (getHp() < 15) {
		return;
	}
	setMp(getMp() + 10);
	setHp(getHp() - 15);
}

string MagicianPlayer::showInfo()
{
	string result;
	stringstream ss;
	result += "職業：MagicianPlayer";
	result += " 名字：" + getName();
	result += " 等級："; ss << level;	result += ss.str();	ss.str("");	ss.clear();
	result += " 經驗："; ss << getExp();	result += ss.str();	ss.str("");	ss.clear();
	result += " 血量："; ss << getHp();	result += ss.str();	ss.str("");	ss.clear();
	result += " 魔力："; ss << getMp();	result += ss.str();	ss.str("");	ss.clear();
	result += " 攻擊力："; ss << attack;	result += ss.str();	ss.str("");	ss.clear();
	result += " 防禦力："; ss << defense;	result += ss.str();	ss.str("");	ss.clear();
	result += " 升級所需經驗值："; ss << lvup_exp;	result += ss.str();	ss.str("");	ss.clear();
	if (getWeapon() != NULL) {
		result += " 裝備武器：" + getWeapon()->name;
	}
	if (getArmor() != NULL) {
		result += " 裝備防護：" + getArmor()->name;
	}

	return result;
}

vector<string> MagicianPlayer::getInfoArray() const
{
	vector<string> infoArray;
	stringstream ss;
	infoArray.push_back("=========== Player Information ===========");
	infoArray.push_back("名字：" + getName());
	infoArray.push_back("職業：MagicianPlayer");
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
	// level //
	ss << getLevel();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';

	if (getWeapon() != nullptr) {
		result += getWeapon()->getEngName();
		result += '$';
	}
	if (getArmor() != nullptr) {
		result += getArmor()->getEngName();
		result += '$';
	}

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
	// level //
	begin = end;
	end = record.find('$', begin + 1);
	ss << string(record, begin + 1, end - begin - 1);
	ss >> lev;
	ss.str("");
	ss.clear();

	// construct object //
	MagicianPlayer* a = new MagicianPlayer(lev, n);
	a->setHp(h);
	a->setMp(m);
	a->setExp(ex);

	if (record.at(end + 1) != '#') {
		begin = end;
		end = record.find('$', begin + 1);

		if (string(record, begin + 1, end - begin - 1) == "Armour") {
			a->armor = new Armour;
		}
		else if (string(record, begin + 1, end - begin - 1) == "GoldenShield") {
			a->armor = new GoldenShield;
		}
		else if (string(record, begin + 1, end - begin - 1) == "DragonKillFalchion") {
			a->weapon = new DragonKillFalchion;
		}
		else if (string(record, begin + 1, end - begin - 1) == "SkywardSword") {
			a->weapon = new SkywardSword;
		}

		if (record.at(end + 1) != '#') {
			begin = end;
			end = record.find('$', begin + 1);

			if (string(record, begin + 1, end - begin - 1) == "Armour") {
				a->armor = new Armour;
			}
			else if (string(record, begin + 1, end - begin - 1) == "GoldenShield") {
				a->armor = new GoldenShield;
			}
			else if (string(record, begin + 1, end - begin - 1) == "DragonKillFalchion") {
				a->weapon = new DragonKillFalchion;
			}
			else if (string(record, begin + 1, end - begin - 1) == "SkywardSword") {
				a->weapon = new SkywardSword;
			}
		}
	}

	return a;
}

