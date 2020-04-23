#ifndef JWMONSTER_H
#define JWMONSTER_H

#include <iostream>
#include <vector>
#include "BaseMonster.h"
using namespace std;

class JWMonster :public BaseMonster {
public:
	JWMonster();
	JWMonster(string n);
	JWMonster(string n, int att, int def, int ex, int mon, int mH, int mP);
	JWMonster(JWMonster& a);

	virtual string serialize();
	static BaseMonster* unserialize(string record);
};

#endif