#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H

#include <iostream>
#include <String>
#include "NovicePlayer.h"
using namespace std;

class KnightPlayer : public NovicePlayer {
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int value, string n);
	KnightPlayer(const KnightPlayer& a);
	virtual void setLevel(int value);

	virtual void setExp(int);
	virtual void addExp(int);
	virtual void addExp(double);
	virtual void minusExp(int);

	virtual void specialSkill(void);
	const string specialSkill_description = "可提升15點血量，但會扣除10點魔力";

	virtual string showInfo();
	virtual vector<string> getInfoArray() const;

	virtual string serialize();

	static NovicePlayer* unserialize(string record);

};


#endif
