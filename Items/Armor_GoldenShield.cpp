#include "Armor_GoldenShield.h"

GoldenShield::GoldenShield()
	:ArmorItem(4, "�����n", "���m�O�W�[10�I", "����4�H�W�~��֦�", 20, 'a', 0, 10, 0)
{
}

string GoldenShield::getEngName()
{
	return string("GoldenShield");
}
