#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include <iostream>
#include "NovicePlayer.h"

using namespace std;

class OrcPlayer : public NovicePlayer {
public:
	OrcPlayer();
	OrcPlayer(int value);
	OrcPlayer(int value, string);
	OrcPlayer(const OrcPlayer& a);
	virtual void setLevel(int value);

	virtual void setExp(int);
	virtual void addExp(int);
	virtual void addExp(double);
	virtual void minusExp(int);

	virtual void specialSkill(void);
	virtual string serialize();

	virtual string showInfo();

	virtual vector<string> getInfoArray() const;

	static NovicePlayer* unserialize(string record);

};

#endif