#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	const int level_required;	// level limit of equip/use this item
	const string name;	// the name of this item
	const string effects;	// a short description of its effect. E.g., ¡§Attack + 100, 20 % of probability making opponents cannot act at the next turn¡¨
	const string description;	// a short description of this item, E.g., ¡§A silver - made hand - shaped weapon.There¡¦s a folklore said that once upon a time, a blacksmith encounteredand was beaten by the JWMaster.While fighting with JWM, he found that the shape of JWM¡¦s hand is so beautiful.So he made a weapon that mimics the shape of JWM¡¦s hand for increasing his ability in self - defense.¡¨
	const int weight;	// the weight of the item
	const char type;	// Type of this item, ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables
	const int need_hands;	// 0 for wearing, 1 for single hand needed, 2 for both hands needed.

	Item(int level_required, string name, string effects, string description, int weight, char type, int need_hands)
		:level_required(level_required), name(name), effects(effects), description(description), weight(weight), type(type), need_hands(need_hands)
	{
	}

	virtual string getEngName() = 0;

};


#endif
