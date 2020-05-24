#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:
	int cursor_position = 0;

public:
	string question_name;
	vector<string> instruction;
	vector<string> options;
	vector<string> option_descriptions;

	Menu();
	int run();

};

#endif