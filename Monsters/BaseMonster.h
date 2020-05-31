#ifndef BASEMONSTER_H
#define BASEMONSTER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BaseMonster {
	friend ostream& operator<<(ostream& output, const BaseMonster& a);
public:
	const string name;	// Name of the monster
	const int attack;	// Attack of the monster
	const int defense;	// Defense of the monster 
	const int exp;	// Experience earned by players after beating this monster
	const int money;	// Amount of money dropped after beating this monster
	const int max_hp;	// The monster¡¦s maximum HP
	const int max_mp;	// The monster¡¦s maximum MP

	BaseMonster(string n, int att, int def, int ex, int mon, int mH, int mP);
	BaseMonster(BaseMonster& a);
	~BaseMonster();

	void setHP(int h);
	void decreaseHp(int value);
	int getHP() const;
	void setMP(int m);
	int getMP() const;

	vector<string> getInfo() const;

	static int getInstanceCount(void);
	virtual string serialize() = 0;


private:
	int hp;	// Current HP of this monster, range: [0, max_hp]
	int mp;	// Current MP of this monster, range: [0, max_mp]
	static int count;	// Number of instances of monster series classes

};


#endif