#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H
#include <iostream>
#include "NovicePlayer.h"

using namespace std;

class MagicianPlayer : public NovicePlayer {
public:
	MagicianPlayer();
	MagicianPlayer(int value);
	MagicianPlayer(int value, string n);
	MagicianPlayer(const MagicianPlayer& a);
	virtual void setLevel(int value);

	virtual void specialSkill(void);
	const string specialSkill_description = "可提升10點魔力，但會扣除15點血量";
	virtual string serialize();

	static NovicePlayer* unserialize(string record);

};

#endif