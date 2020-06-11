#include "Armor_Armour.h"

Armour::Armour()
	:ArmorItem(2, "盔甲", "防禦力增加5點", "等級2以上才能擁有", 15, 'a', 0, 5, 0)
{
}

string Armour::getEngName()
{
	return "Armour";
}
