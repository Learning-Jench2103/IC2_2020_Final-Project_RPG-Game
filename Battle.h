#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include "NovicePlayer.h"
#include "BaseMonster.h"
using namespace std;

struct Character {
	char type; // monster or player?
	bool alive; // alive or dead?
	void* instance; // pointer to instance
};

class Battle {
private:
	int n_turn;	// The number of turn, should be initialized to 0 in constructor
	int turn_limit;	// Maximum number of turn, 0 for no limit
	Character* action_list;	// An ordered action list, indicates the order of action
	pair<int, int> actor_num;	// (n_player, n_monster)
	int current_actor;
	bool playerWin();
	bool monsterWin();
	inline void reward();

public:
	Battle(NovicePlayer** player, BaseMonster** monster, int n_player, int n_monster, int turn_lim);
	// First parameter indicates the array / list of players to attend
	// The second one is for monsters
	// The thirdand forth parameter indicates the number of players and monsters
	// The fifth parameter represents the limit on number of turns

	Battle(NovicePlayer** player, BaseMonster** monster, int n_player, int n_monster);
	// The fifth parameter is omitted, set turn_limit to 0
	// This means this battle has no limit on number of turns

	~Battle();
	// The destructor will delete only action_list array

	bool nextActor(void);
	// Move to next actor, if all character were done, n_turn++
	// The return value indicates whether it exceeds limit on number of turns

	int getTurnCount(void) const;
	// Get the current number of turn

	int getTurnLimit(void) const;
	// Get the limit on number of turns, 0 for no limit

	bool attack(Character* actor1, Character* actor2, bool specialSkill);

	int getPlayerCount(void) const;

	int getPlayerCount(bool a) const;
	// Get the current number of players
	// If the second parameter set to true, only alive players will be counted
	// If the second parameter is omitted, return count for all players

	int getMonsterCount(void) const;

	int getMonsterCount(bool a) const;
	// Similar to above ones, but this set of methods return the information of monsters

	Character getCurrentActor(void);
	// Get the current actor within the action list
	// Note that the type of return value is struct Character

	Character* getPlayers(void);
	// Get a full list of players, no matter dead or alive ones

	Character* getMonsters(void);
	// Get a full list of monsters, no matter dead or alive ones

};

#endif