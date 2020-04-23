#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include <iostream>
#include "NovicePlayer.h"

using namespace std;

class OrcPlayer: public NovicePlayer {
public:
	OrcPlayer();
	OrcPlayer(int value);
	OrcPlayer(int value, string);
	OrcPlayer(const OrcPlayer& a);
	virtual void setLevel(int value);

	virtual void specialSkill(void);
	virtual string serialize();

	static NovicePlayer* unserialize(string record);

};

#endif