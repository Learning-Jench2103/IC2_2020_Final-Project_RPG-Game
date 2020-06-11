#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Menu
{
private:
	int cursor_position = 0;
	void setColor(int color = 7);
	void setCursor(int x, int y, int& next_row);

public:
	string question_name;
	vector<string> instruction;
	vector<string> options;
	vector<string> option_descriptions;

	Menu();
	int run();

};

#endif