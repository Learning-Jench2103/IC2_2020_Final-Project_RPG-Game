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

	virtual void setExp(int);
	virtual void addExp(int);
	virtual void addExp(double);
	virtual void minusExp(int);

	virtual void specialSkill(void);
	const string specialSkill_description = "�i����10�I�]�O�A���|����15�I��q";

	virtual string showInfo();

	virtual vector<string> getInfoArray() const;

	virtual string serialize();

	static NovicePlayer* unserialize(string record);

};

#endif