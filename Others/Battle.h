#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <vector>
using namespace std;

class NovicePlayer;
class BaseMonster;

struct Character {
	char type; // monster or player?
	bool alive; // alive or dead?
	void* instance; // pointer to instance
};

class Battle {
private:
	int current_turn = 0;	// The number of turn, should be initialized to 0 in constructor
	int turn_limit;	// Maximum number of turn, 0 for no limit
	vector<Character*> action_list;	// An ordered action list, indicates the order of action
	int player_number;
	int monster_number;
	int current_actor = 0;	// index of item in action_list
	inline void reward();

public:
	Battle(vector<NovicePlayer*> player, vector<BaseMonster*> monster, int turn_lim);

	~Battle();

	bool nextActor(void);	// True if there is a next actor and False if the battle ends

	int getCurrentTurn(void) const;

	int getTurnLimit(void) const;	// Get the limit on number of turns, 0 for no limit

	bool attack(Character& actor_1, Character& actor_2, bool specialSkill);

	int getPlayerNumber(void) const;
	int getPlayerNumber(bool alive) const;
	// Get the current number of players
	// If the second parameter set to true, only alive players will be counted
	// If the second parameter is omitted, return count for all players

	int getMonsterNumber(void) const;
	int getMonsterNumber(bool alive) const;	// Similar to above ones, but this set of methods return the information of monsters

	Character* getCurrentActor(void) const;
	// Get the current actor within the action list
	// Note that the type of return value is struct Character

	vector<Character*> getPlayers(void) const;	// Get a full list of players, no matter dead or alive ones
	vector<Character*> getMonsters(void) const;	// Get a full list of monsters, no matter dead or alive ones
	vector<Character*> getOpponents(void) const;

	bool playerWin();
	bool monsterWin();
};

#endif