#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H

#include <iostream>
#include "NovicePlayer.h"
using namespace std;

class KnightPlayer : public NovicePlayer {
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int value, string n);
	KnightPlayer(const KnightPlayer& a);
	virtual void setLevel(int value);

	virtual void specialSkill(void);
	virtual string serialize();

	static NovicePlayer* unserialize(string record);

};


#endif
