#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H
#include <iostream>
#include "NovicePlayer.h"

using namespace std;

class MagicianPlayer : public NovicePlayer {
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	void pray(NovicePlayer& a);

};

#endif