#include "Armor_GoldenShield.h"

GoldenShield::GoldenShield()
	:ArmorItem(4, "金鐘罩", "防禦力增加10點", "等級4以上才能擁有", 20, 'a', 0, 10, 0)
{
}

string GoldenShield::getEngName()
{
	return string("GoldenShield");
}
