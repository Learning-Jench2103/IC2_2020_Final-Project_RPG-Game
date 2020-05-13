#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "Backpack.h"

using namespace std;

class Item;
class WeaponItem;
class ArmorItem;
class ConsumableItem;


class NovicePlayer {
	friend ostream& operator<<(ostream&, const NovicePlayer&);
private:
	string name; // Name of the player
	int hp;	// Current HP of the player, range: [0, max_hp]
	int mp;	// Current MP of the player, range: [0, max_mp]
	int exp;	// Cumulative experience of the player, >= 0
				// Will not reset to zero after leveling-up
	int money;	// Current amount of money that player carries, >= 0

	WeaponItem* weapon = NULL; // weapon item
	ArmorItem* armor = NULL; // armor item

	Backpack backpack;

protected:
	int level;	// The level of the player, >= 1
	int attack;	// Attack of the player
	int defense;	// Defense of the player
	int max_hp;	// Max HP of the player
	int max_mp;	// Max MP of the player
	int lvup_exp;	// Experience needed for leveling-up

public:
	NovicePlayer();	//With level = 1, name = ¡§anonymous¡¨
	NovicePlayer(int);	//Initializes level of the player, name = ¡§anonymous¡¨
	NovicePlayer(int, string);	//Initializes leveland name of the player
	NovicePlayer(const NovicePlayer&);
	~NovicePlayer();
	void setName(string);
	string getName() const;
	virtual void setLevel(int);	// also calculate attack, defense, max_hp, max_mp and lvup_exp
	int getLevel() const;
	void setHp(int);	// should not greater than max_hp
	int getHp() const;
	void setMp(int);	// should not greater than max_mp
	int getMp() const;
	void setExp(int);
	void addExp(int);
	void addExp(double);
	int getExp() const;
	void setMoney(int);
	void addMoney(int);
	int getMoney() const;
	void setAttack(int);
	int getAttack(void) const;
	void setDefense(int);
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;

	virtual void specialSkill(void);

	bool equipWeapon(WeaponItem* weapon);
	bool equipArmor(ArmorItem* armor);
	void useConsumable(ConsumableItem* consumable);

	/* backpack */
	int getCurrentBackpackWeight(void) const;
	int getBackpackWeightLimit(void) const;
	vector<string> showBackpack(void) const;
	vector<string> showItemInfo(int index) const;
	int getItemAmount(void) const;
	Item* getItemPtr(int index);
	bool putItem(Item* item);

	virtual string serialize();
	static NovicePlayer* unserialize(string record);

	/*
	About all constructors and set-functions:
		1.If the argument is greater than the maximum limit of a variable, set the data as the maximum limit.
		2.If the argument is less than the minimum limit, set the data as the minimum limit.
		3.If a argument of the copy constructor is a derived class object and its data range is different from this class,
			then the data will be changed in proportion.
		4.Derived classes should check or set all values of data again after calling copy constructor of this class to make sure
			they are set correctly.
	*/

};

#endif