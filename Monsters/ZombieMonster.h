#ifndef ZOMBIEMONSTER_H
#define ZOMBIEMONSTER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "BaseMonster.h"
using namespace std;

class ZombieMonster :public BaseMonster {
	public:
	ZombieMonster();
	ZombieMonster(string n);
	ZombieMonster(string n, int att, int def, int ex, int mon, int mH, int mP);
	ZombieMonster(ZombieMonster& a);

	virtual string serialize();
	static BaseMonster* unserialize(string record);
};


#endif
