#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H

#include <iostream>
#include "NovicePlayer.h"
using namespace std;

class KnightPlayer : public NovicePlayer {
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	void setLevel(int);
	void heal(NovicePlayer&);

};


#endif
