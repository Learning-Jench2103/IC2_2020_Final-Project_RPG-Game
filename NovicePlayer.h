#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iostream>

using namespace std;

class NovicePlayer {
private:
	string name; // Name of the player
	int hp;	// Current HP of the player, range: [0, max_hp]
	int mp;	// Current MP of the player, range: [0, max_mp]
	int exp;	// Cumulative experience of the player, >= 0
				// Will not reset to zero after leveling-up
	int money;	// Current amount of money that player carries, >= 0

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
	void setName(string);
	string getName() const;
	void setLevel(int);	// also calculate attack, defense, max_hp, max_mp and lvup_exp 
	int getLevel() const;
	void setHp(int);	// should not greater than max_hp
	int getHp() const;
	void setMp(int);	// should not greater than max_mp
	int getMp() const;
	void setExp(int);	// should not greater than lvup_exp
	int getExp() const;
	void setMoney(int);
	int getMoney() const;
	int getAttack(void) const;
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;

	/*
	About all set-functions:
		1.If the argument is greater than the maximum limit, set the data as the maximum limit.
		2.If the argument is less than the minimum limit, set the data as the minimum limit.
		3.As long as a derived class has changed data of limit-values in this class, all the set-functions of this class will 
			follow the new limits. So derived classes can use set-functions of this class directly.
	*/

};

#endif