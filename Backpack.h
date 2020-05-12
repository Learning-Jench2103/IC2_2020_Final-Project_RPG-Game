#ifndef BACKPACK_H
#define BACKPACK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item;

class Backpack {
private:
	vector<Item*> backpack;
	int backpack_weight = 0; // current weight of player¡¦s backpack
	int backpack_weight_limit; // limit on weight of backpack

public:
	Backpack();
	Backpack(int backpack_weight_limit);
	bool setWeightLimit(int new_weight_limit);

	bool putItem(Item* item);
	Item* takeItem(int index);
	
	int getCurrentBackpackWeight(void) const;
	int getBackpackWeightLimit(void) const;
	vector<string> showBackpack(void) const;
	vector<string> showItemInfo(int index) const;
	int getItemAmount(void) const;
};


#endif
