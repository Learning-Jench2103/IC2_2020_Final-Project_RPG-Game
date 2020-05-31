#include "OrcPlayer.h"
#include "../Items/base/ArmorItem.h"
#include "../Items/base/WeaponItem.h"
#include <string>
#include <sstream>

OrcPlayer::OrcPlayer()
	:NovicePlayer()
{
	setLevel(1);	// OrcPlayer::setLevel(int value)
	setHp(max_hp);
	setMp(max_mp);
}

OrcPlayer::OrcPlayer(int value)
	: NovicePlayer(value)
{
	setLevel(value);	// OrcPlayer::setLevel(int value)
}

OrcPlayer::OrcPlayer(int value, string n)
	: NovicePlayer(value, n)
{
	setLevel(value);	// OrcPlayer::setLevel(int value)
}

OrcPlayer::OrcPlayer(const OrcPlayer& a)
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

void OrcPlayer::setLevel(int value)
{
	if (value < 1) {
		level = 1;
	}
	else {
		level = value;
	}
	max_hp = 200 + 20 * level;
	max_mp = 50 + 5 * level;
	setHp(max_hp);
	setMp(max_mp);
	attack = 50 + 12 * level;
	defense = 30 + 10 * level;
	lvup_exp = pow(10, log2(level + 1));
}

void OrcPlayer::setExp(int value)
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

void OrcPlayer::addExp(int a)
{
	setExp(getExp() + a);
}

void OrcPlayer::addExp(double ratio)
{
	setExp(getExp() + lvup_exp * (ratio));
}

void OrcPlayer::minusExp(int value)
{
	setExp(getExp() - value);
}

void OrcPlayer::specialSkill(void)
{

}

string OrcPlayer::serialize()
{
	stringstream ss;
	string result;
	result += "@OrcPlayer$";
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
	/*
	// money //
	ss << getMoney();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '$';
	*/
	// level //
	ss << getLevel();
	result += ss.str();
	ss.str("");
	ss.clear();
	result += '#';	// end signal

	return result;
}

string OrcPlayer::showInfo()
{
	string result;
	stringstream ss;
	result += "¾�~�GOrcPlayer     ";
	result += " �W�r�G" + getName();
	result += " ���šG"; ss << level;	result += ss.str();	ss.str("");	ss.clear();
	result += " �g��G"; ss << getExp();	result += ss.str();	ss.str("");	ss.clear();
	result += " ��q�G"; ss << getHp();	result += ss.str();	ss.str("");	ss.clear();
	result += " �]�O�G"; ss << getMp();	result += ss.str();	ss.str("");	ss.clear();
	result += " �����O�G"; ss << attack;	result += ss.str();	ss.str("");	ss.clear();
	result += " ���m�O�G"; ss << defense;	result += ss.str();	ss.str("");	ss.clear();
	result += " �ɯũһݸg��ȡG"; ss << lvup_exp;	result += ss.str();	ss.str("");	ss.clear();
	if (getWeapon() != NULL) {
		result += " �˳ƪZ���G" + getWeapon()->name;
	}
	if (getArmor() != NULL) {
		result += " �˳ƨ��@�G" + getArmor()->name;
	}

	return result;
}

vector<string> OrcPlayer::getInfoArray() const
{
	vector<string> infoArray;
	stringstream ss;
	infoArray.push_back("=========== Player Information ===========");
	infoArray.push_back("�W�r�G" + getName());
	infoArray.push_back("¾�~�GOrcPlayer");
	ss << getLevel(); infoArray.push_back("���šG" + ss.str()); ss.str(""); ss.clear();
	ss << getHp(); infoArray.push_back("��q�G" + ss.str()); ss.str(""); ss.clear();
	ss << getMp(); infoArray.push_back("�]�O�G" + ss.str()); ss.str(""); ss.clear();
	ss << getAttack(); infoArray.push_back("�����O�G" + ss.str()); ss.str(""); ss.clear();
	ss << getDefense(); infoArray.push_back("���m�O�G" + ss.str()); ss.str(""); ss.clear();
	ss << getExp(); infoArray.push_back("�g��ȡG" + ss.str()); ss.str(""); ss.clear();
	ss << getMaxHP(); infoArray.push_back("�̤j��q�G" + ss.str()); ss.str(""); ss.clear();
	ss << getMaxMP(); infoArray.push_back("�̤j�]�O�G" + ss.str()); ss.str(""); ss.clear();
	ss << getLvupExp(); infoArray.push_back("�U�@���Ÿg��ȡG" + ss.str()); ss.str(""); ss.clear();
	infoArray.push_back("==========================================");
	return infoArray;
}

NovicePlayer* OrcPlayer::unserialize(string record)
{
	size_t begin, end;
	stringstream ss;
	begin = record.find('@');
	end = record.find('$', begin);
	// check class name //
	if (string(record, begin + 1, end - begin - 1) != "OrcPlayer") {
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
	OrcPlayer* a = new OrcPlayer(lev, n);
	a->setHp(h);
	a->setMp(m);
	a->setExp(ex);
	//a->setMoney(mon);

	return a;
}
