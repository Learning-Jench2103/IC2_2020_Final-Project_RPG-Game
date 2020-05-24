#ifndef GOBLINMONSTER_H
#define GOBLINMONSTER_H

#include <iostream>
#include <vector>
#include "BaseMonster.h"
using namespace std;

class GoblinMonster :public BaseMonster {
public:
	GoblinMonster();
	GoblinMonster(string n);
	GoblinMonster(string n, int att, int def, int ex, int mon, int mH, int mP);
	GoblinMonster(GoblinMonster& a);

	virtual string serialize();
	static BaseMonster* unserialize(string record);
};

#endif