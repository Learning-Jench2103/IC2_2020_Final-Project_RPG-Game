#ifndef BACKPACK_H
#define BACKPACK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item;
class NovicePlayer;

class Backpack {
private:
	vector<Item*> backpack;
	vector<NovicePlayer*>* player_list;
	int backpack_weight = 0; // current weight of player¡¦s backpack
	int backpack_weight_limit; // limit on weight of backpack

	void setCursor(int x, int y) const;

public:
	Backpack();
	~Backpack();

	void setPlayerList(vector<NovicePlayer*>* player_list);
	bool setWeightLimit(int new_weight_limit);
	void addWeightLimit();	// add 2

	bool putItem(Item* item);
	Item* takeItem(int index);
	
	int getCurrentBackpackWeight(void) const;
	int getBackpackWeightLimit(void) const;
	vector<string> showBackpack(void) const;
	string showItemInfo(int index) const;
	int getItemAmount(void) const;

	void display();

	void clear();

	string serialize() const;
	void unserialize(string record);

};


#endif
