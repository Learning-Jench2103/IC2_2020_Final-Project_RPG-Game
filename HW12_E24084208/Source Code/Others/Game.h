#ifndef GAME_H
#define GAME_H

#include "Backpack.h"
#include "Battle.h"
#include "Field.h"
#include "Menu.h"
#include "../Players/NovicePlayer.h"
#include "../Players/OrcPlayer.h"
#include "../Players/KnightPlayer.h"
#include "../Players/MagicianPlayer.h"
#include "../Monsters/BaseMonster.h"
#include "../Monsters/GoblinMonster.h"
#include "../Monsters/ZombieMonster.h"
#include "../Monsters/JWMonster.h"
#include "../Events/NotNotGame.h"
#include "../Events/EndScreen.h"
#include "../Events/Welcome_1F.h"
#include "../Events/Welcome_2F.h"
#include "../Events/End_2F.h"
#include "../Events/Welcome_3F.h"
#include "Store.h"
#include "legend_1F.h"
#include "legend_2F.h"
#include "legend_3F.h"

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Game
{
private:
	vector<NovicePlayer*> player_list;	// need serialize
	Backpack backpack;	// need serialize	// pointer

	unsigned int money;	// need serialize

	Menu Main_Menu;
	Store* store;

	Menu* player_screen = nullptr;

	int step_count = 0;

	Field* current_field;	// need serialize

	Field* First_floor;	// need serialize
	Field* Second_floor;	// need serialize
	Field* Third_floor;	// need serialize

	unsigned int paper_amount;	// need serialize

	int all_player_level_sigma;	// need serialize

	bool second_floor_entered;	// need serialize
	bool third_floor_entered;	// need serialize

	bool second_floor_finish;	// need serialize

	bool first_notnot;	// need serialize
	bool second_notnot;	// need serialize

	bool goblin_monster_killed;	// need serialize
	bool zombie_monster_killed;	// need serialize

	bool reset = true;

	void generatePlayers();
	void initializeFirstFloor();
	void initializeSecondFloor();
	void initializeThirdFloor();

	void setCursor(int x, int y) const;
	void setColor(unsigned int color = 7) const;

	bool play();
	void serialize();
	void unserialize();


public:
	Game();
	~Game();
	void run();

};

#endif