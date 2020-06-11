#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "../Others/Backpack.h"

using namespace std;

class Item;
class WeaponItem;
class ArmorItem;
class ConsumableItem;


class NovicePlayer {
	friend ostream& operator<<(ostream&, const NovicePlayer&);
private:
	string name; // Name of the player
	int hp = 0;	// Current HP of the player, range: [0, max_hp]
	int mp = 0;	// Current MP of the player, range: [0, max_mp]
	int exp;	// Cumulative experience of the player, >= 0
				// Will not reset to zero after leveling-up
	//int money;	// Current amount of money that player carries, >= 0

	//Backpack backpack;

protected:
	int level;	// The level of the player, >= 1
	int attack;	// Attack of the player
	int defense;	// Defense of the player
	int max_hp = 110;	// Max HP of the player
	int max_mp = 45;	// Max MP of the player
	int lvup_exp;	// Experience needed for leveling-up

	WeaponItem* weapon = nullptr; // weapon item
	ArmorItem* armor = nullptr; // armor item

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
	void addHp(int);
	void decreaseHp(int);
	void setHp(int);	// should not greater than max_hp
	int getHp() const;
	void setMp(int);	// should not greater than max_mp
	int getMp() const;
	virtual void setExp(int);
	virtual void addExp(int);
	virtual void addExp(double);
	virtual void minusExp(int);
	int getExp() const;
	//void setMoney(int);
	//void addMoney(int);
	//int getMoney() const;
	void setAttack(int);
	int getAttack(void) const;
	void setDefense(int);
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;
	virtual string showInfo();

	WeaponItem* getWeapon();
	ArmorItem* getArmor();

	virtual void specialSkill(void);

	bool equipWeapon(WeaponItem* weapon, Backpack* backpack);
	bool equipArmor(ArmorItem* armor, Backpack* backpack);
	void useConsumable(ConsumableItem* consumable);

	virtual vector<string> getInfoArray() const;


	/* backpack */
	/*
	int getCurrentBackpackWeight(void) const;
	int getBackpackWeightLimit(void) const;
	vector<string> showBackpack(void) const;
	vector<string> showItemInfo(int index) const;
	int getItemAmount(void) const;
	Item* getItemPtr(int index);
	bool putItem(Item* item);
	void displayBackpack();
	*/

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