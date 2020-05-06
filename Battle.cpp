#include "Battle.h"

bool Battle::playerWin()
{
	for (int i = 0; i < actor_num.first + actor_num.second; i++) {
		if (action_list[i].type == 'm' && action_list[i].alive) {
			return false;
		}
	}
	return true;
}

bool Battle::monsterWin()
{
	for (int i = 0; i < actor_num.first + actor_num.second; i++) {
		if (action_list[i].type == 'p' && action_list[i].alive) {
			return false;
		}
	}
	return true;
}

void Battle::reward()
{
	int money = 0;
	for (int i = 0; i < actor_num.first + actor_num.second; i++) {
		if (action_list[i].type == 'm') {
			money += static_cast<BaseMonster*>(action_list[i].instance)->money;
		}
	}

	for (int i = 0; i < actor_num.first + actor_num.second; i++) {
		if (action_list[i].type == 'p' && action_list[i].alive) {
			static_cast<NovicePlayer*>(action_list[i].instance)->addExp((double)actor_num.second / actor_num.first * 0.2);
			static_cast<NovicePlayer*>(action_list[i].instance)->addMoney(money);
		}
	}
}

Battle::Battle(NovicePlayer** player, BaseMonster** monster, int n_player, int n_monster, int turn_lim)
	:turn_limit(turn_lim), n_turn(0), actor_num(n_player, n_monster), current_actor(0)
{
	action_list = new Character[n_player + n_monster];

	for (int i = 0; i < n_player; i++) {
		action_list[i].type = 'p';
		action_list[i].alive = true;
		action_list[i].instance = player[i];
	}

	for (int i = 0; i < n_monster; i++) {
		action_list[i + n_player].type = 'm';
		action_list[i + n_player].alive = true;
		action_list[i + n_player].instance = monster[i];
	}
}

Battle::Battle(NovicePlayer** player, BaseMonster** monster, int n_player, int n_monster)
	: turn_limit((n_player + n_monster) / 2), n_turn(0), actor_num(n_player, n_monster), current_actor(0)
{
	action_list = new Character[n_player + n_monster];

	for (int i = 0; i < n_player; i++) {
		action_list[i].type = 'p';
		action_list[i].alive = true;
		action_list[i].instance = player[i];
	}

	for (int i = 0; i < n_monster; i++) {
		action_list[i + n_player].type = 'm';
		action_list[i + n_player].alive = true;
		action_list[i + n_player].instance = monster[i];
	}
}

Battle::~Battle()
{
	delete[] action_list;
}

bool Battle::nextActor(void)
{
	if (n_turn == turn_limit - 1 && current_actor == actor_num.first + actor_num.second - 1) {
		return false;
	}

	if (playerWin()) {
		reward();
		return false;
	}

	if (current_actor == actor_num.first + actor_num.second - 1) {
		current_actor = 0;
		++n_turn;
	}
	else {
		++current_actor;
	}

	if (!action_list[current_actor].alive) {
		return nextActor();
	}
	else {
		return true;
	}
}

int Battle::getTurnCount(void) const
{
	return n_turn;
}

int Battle::getTurnLimit(void) const
{
	return turn_limit;
}

bool Battle::attack(Character* actor_1, Character* actor_2, bool specialSkill = false)
{
	NovicePlayer* p_ptr;
	BaseMonster* m_ptr;
	int att;

	if (actor_1->type == 'm' && actor_2->type == 'p') {
		m_ptr = static_cast<BaseMonster*>(actor_1->instance);
		p_ptr = static_cast<NovicePlayer*>(actor_2->instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
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
		if (p_ptr->getHp() == 0) {
			actor_2->alive = false;
		}
		return true;
	}
	else if (actor_1->type == 'p' && actor_2->type == 'm') {
		p_ptr = static_cast<NovicePlayer*>(actor_1->instance);
		m_ptr = static_cast<BaseMonster*>(actor_2->instance);
		if (specialSkill) {
			p_ptr->specialSkill();
		}
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
		if (m_ptr->getHP() == 0) {
			actor_2->alive = false;
		}
		return true;
	}
	return false;
}

int Battle::getPlayerCount(void) const
{
	return actor_num.first;
}

int Battle::getPlayerCount(bool a) const
{
	int count = 0;
	for (int i = 0; i < actor_num.first; i++) {
		if (action_list[i].alive) {
			count++;
		}
	}

	if (a) {
		return count;
	}
	else {
		return (actor_num.first - count);
	}
}

int Battle::getMonsterCount(void) const
{
	return actor_num.second;
}

int Battle::getMonsterCount(bool a) const
{
	int count = 0;
	for (int i = actor_num.first; i < actor_num.first + actor_num.second; i++) {
		if (action_list[i].alive) {
			count++;
		}
	}

	if (a) {
		return count;
	}
	else {
		return (actor_num.second - count);
	}
}

Character Battle::getCurrentActor(void)
{
	return action_list[current_actor];
}

Character* Battle::getPlayers(void)
{
	Character* player = new Character[actor_num.first];
	for (int i = 0; i < actor_num.first; i++) {
		player[i] = action_list[i];
	}
	return player;
}

Character* Battle::getMonsters(void)
{
	Character* monster = new Character[actor_num.second];
	for (int i = 0; i < actor_num.second; i++) {
		monster[i] = action_list[actor_num.first + i];
	}
	return monster;
}
