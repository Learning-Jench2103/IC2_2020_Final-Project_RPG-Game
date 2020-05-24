#include "Backpack.h"
#include "../Items/base/Item.h"
#include <sstream>

Backpack::Backpack()
{
	backpack_weight_limit = 10;
}

Backpack::Backpack(int backpack_weight_limit)
{
	Backpack::backpack_weight_limit = backpack_weight_limit;
}

bool Backpack::putItem(Item* item)
{
	if (backpack_weight >= backpack_weight_limit) {
		return false;
	}
	backpack.push_back(item);
	backpack_weight += item->weight;
	return true;
}

Item* Backpack::takeItem(int index)
{
	if (index >= backpack.size()) {
		return nullptr;
	}
	Item* taken = backpack.at(index);
	backpack.erase(backpack.begin() + index);
	backpack_weight -= taken->weight;
	return taken;
}

bool Backpack::setWeightLimit(int new_weight_limit)
{
	if (new_weight_limit < backpack_weight) {
		return false;
	}
	backpack_weight_limit = new_weight_limit;
	return true;
}

int Backpack::getCurrentBackpackWeight(void) const
{
	return backpack_weight;
}

int Backpack::getBackpackWeightLimit(void) const
{
	return backpack_weight_limit;
}

vector<string> Backpack::showBackpack(void) const
{
	vector<string> result;
	for (int i = 0; i < backpack.size(); i++) {
		result.push_back(backpack.at(i)->name);
	}
	return result;
}

vector<string> Backpack::showItemInfo(int index) const
{
	vector<string> result;
	stringstream ss;
	result.push_back("Effect: " + backpack.at(index)->effects);
	result.push_back("Description: " + backpack.at(index)->description);
	/* weight */
	ss << backpack.at(index)->weight;
	result.push_back("Weight = " + ss.str());
	ss.str("");	ss.clear();
	/* level_required */
	ss << backpack.at(index)->level_required;
	result.push_back("Required Level = " + ss.str());
	ss.str("");	ss.clear();
	/* need_hands */
	if (backpack.at(index)->need_hands == 1) {
		result.push_back("You should use 1 hand to hold this item.");
	}
	else if (backpack.at(index)->need_hands == 2) {
		result.push_back("You should use 2 hands to hold this item.");
	}
	else if (backpack.at(index)->need_hands == 0) {
		result.push_back("You can wear it to gain its function.");
	}

	return result;
}

int Backpack::getItemAmount(void) const
{
	return backpack.size();
}
