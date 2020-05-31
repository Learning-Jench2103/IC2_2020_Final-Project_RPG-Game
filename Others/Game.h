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
#include "Store.h"

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Game
{
private:
	vector<NovicePlayer*> player_list;
	Backpack backpack;

	unsigned int money = 0;

	Menu Main_Menu;
	Store* store;
	Menu* backpack_screen = nullptr;
	Menu* player_screen = nullptr;

	int step_count = 0;

	Field* current_field;

	Field* First_floor;
	Field* Second_floor;
	Field* Third_floor;

	unsigned int paper_amount = 0;

	int all_player_level_sigma = 0;

	bool second_floor_entered = false;
	bool third_floor_entered = false;
	bool fourth_floor_entered = false;

	bool first_floor_finish = false;
	bool second_floor_finish = false;
	bool third_floor_finish = false;

	bool first_notnot = false;
	bool second_notnot = false;

	bool goblin_monster_killed = false;
	bool zombie_monster_killed = false;

	void generatePlayers();

	void setCursor(int x, int y) const;
	void setColor(unsigned int color = 7) const;

public:
	Game();
	~Game();
	void run();
	
};

#endif