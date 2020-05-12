#include "Battle.h"
#include "NovicePlayer.h"
#include "BaseMonster.h"

inline void Battle::reward()
{
	int money = 0;
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list[i]->type == 'm') {
			money += static_cast<BaseMonster*>(action_list[i]->instance)->money;
		}
	}

	for (int i = 0; i < action_list.size(); i++) {
		if (action_list[i]->type == 'p' && action_list[i]->alive) {
			static_cast<NovicePlayer*>(action_list[i]->instance)->addExp((double)monster_number / player_number * 0.2);
			static_cast<NovicePlayer*>(action_list[i]->instance)->addMoney(money);
		}
	}
}

Battle::Battle(vector<NovicePlayer*> player, vector<BaseMonster*> monster, int turn_limit = 0)
{
	Battle::turn_limit = turn_limit;
	action_list.resize(player.size() + monster.size());
	for (int i = 0; i < player.size(); i++) {
		action_list.at(i) = new Character;
		action_list.at(i)->type = 'p';
		action_list.at(i)->alive = true;
		action_list.at(i)->instance = player.at(i);
	}
	for (int j = 0; j < monster.size(); j++) {
		action_list.at(player.size() + j) = new Character;
		action_list.at(player.size() + j)->type = 'm';
		action_list.at(player.size() + j)->alive = true;
		action_list.at(player.size() + j)->instance = monster.at(j);
	}

	player_number = player.size();
	monster_number = monster.size();
}

Battle::~Battle()
{
	for (int i = 0; i < action_list.size(); i++) {
		delete action_list[i];
	}
}

bool Battle::nextActor(void)
{
	if (current_turn == turn_limit - 1 && current_actor == action_list.size() - 1) {
		return false;
	}

	if (playerWin()) {
		reward();
		return false;
	}

	if (current_actor == action_list.size() - 1) {
		current_actor = 0;
		++current_turn;
	}
	else {
		++current_actor;
	}

	if (!action_list[current_actor]->alive) {
		return nextActor();
	}
	else {
		return true;
	}
}

int Battle::getCurrentTurn(void) const
{
	return current_turn;
}

int Battle::getTurnLimit(void) const
{
	return turn_limit;
}

bool Battle::attack(Character& actor_1, Character& actor_2, bool specialSkill = false)
{
	NovicePlayer* p_ptr;
	BaseMonster* m_ptr;
	int att;

	if (actor_1.type == 'm' && actor_2.type == 'p') {
		m_ptr = static_cast<BaseMonster*>(actor_1.instance);
		p_ptr = static_cast<NovicePlayer*>(actor_2.instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
		// need adjustment //
		att = m_ptr->attack * 0.2;
		if (att > p_ptr->getDefense() * 0.3) {
			att -= p_ptr->getDefense() * 0.3;
		}
		else if (att > p_ptr->getDefense() * 0.15) {
			att -= p_ptr->getDefense() * 0.15;
		}
		else {
			att /= 2;
		}
		p_ptr->setHp(p_ptr->getHp() - att);
		// need adjustment //
		if (p_ptr->getHp() == 0) {
			actor_2.alive = false;
		}
		return true;
	}
	else if (actor_1.type == 'p' && actor_2.type == 'm') {
		p_ptr = static_cast<NovicePlayer*>(actor_1.instance);
		m_ptr = static_cast<BaseMonster*>(actor_2.instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
		// need adjustment //
		att = p_ptr->getAttack();
		if (att > m_ptr->defense * 0.2) {
			att -= m_ptr->defense * 0.2;
		}
		else if (att > m_ptr->defense * 0.1) {
			att -= m_ptr->defense * 0.1;
		}
		else {
			att /= 2;
		}
		m_ptr->setHP(m_ptr->getHP() - att);
		// need adjustment //
		if (m_ptr->getHP() == 0) {
			actor_2.alive = false;
		}
		return true;
	}
	return false;
}

int Battle::getPlayerNumber(void) const
{
	return player_number;
}

int Battle::getPlayerNumber(bool alive) const
{
	int count = 0;
	for (int i = 0; i < player_number; i++) {
		if (action_list[i]->alive) {
			count++;
		}
	}

	if (alive) {
		return count;
	}
	else {
		return (player_number - count);
	}
}

int Battle::getMonsterNumber(void) const
{
	return monster_number;
}

int Battle::getMonsterNumber(bool alive) const
{
	int count = 0;
	for (int i = 0; i < monster_number; i++) {
		if (action_list[i + player_number]->alive) {
			count++;
		}
	}

	if (alive) {
		return count;
	}
	else {
		return (monster_number - count);
	}
}

Character* Battle::getCurrentActor(void) const
{
	return action_list.at(current_actor);
}

vector<Character*> Battle::getPlayers(void) const
{
	vector<Character*> result;
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'p') {
			result.push_back(action_list.at(i));
		}
	}
	return result;
}

vector<Character*> Battle::getMonsters(void) const
{
	vector<Character*> result;
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'm') {
			result.push_back(action_list.at(i));
		}
	}
	return result;
}

vector<Character*> Battle::getOpponents(void) const
{
	vector<Character*> result;
	if (action_list.at(current_actor)->type == 'p') {
		for (int i = 0; i < action_list.size(); i++) {
			if (action_list.at(i)->type == 'm' && action_list.at(i)->alive) {
				result.push_back(action_list.at(i));
			}
		}
	}
	else {
		for (int i = 0; i < action_list.size(); i++) {
			if (action_list.at(i)->type == 'p' && action_list.at(i)->alive) {
				result.push_back(action_list.at(i));
			}
		}
	}
	return result;
}

bool Battle::playerWin()
{
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'm' && action_list.at(i)->alive) {
			return false;
		}
	}
	return true;
}

bool Battle::monsterWin()
{
	for (int i = 0; i < action_list.size(); i++) {
		if (action_list.at(i)->type == 'p' && action_list.at(i)->alive) {
			return false;
		}
	}
	return true;
}

