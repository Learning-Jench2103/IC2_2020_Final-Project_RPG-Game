#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include <iostream>
#include "NovicePlayer.h"

using namespace std;

class OrcPlayer: public NovicePlayer {
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);

};

#endif