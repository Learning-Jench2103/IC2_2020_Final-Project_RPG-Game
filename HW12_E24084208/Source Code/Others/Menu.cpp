#include "Menu.h"
#include <Windows.h>
#include <conio.h>

void Menu::setColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Menu::setCursor(int x, int y, int& next_row)
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);

	next_row = y + 1;
}

Menu::Menu()
{
}

int Menu::run()
{
	int next_row;	// next line number of the cursor position
	int option_row;	// the line of the first option
	int description_row;	// the line of the first description
	setColor();

	// Question //
	setCursor(3, 1, next_row);
	cout << "【 " << question_name << " 】";

	// Instruction //
	{
		next_row++;
		for (int i = 0; i < instruction.size(); i++) {
			setCursor(3, next_row, next_row);
			cout << instruction.at(i);
		}
	}

	// Options Block //
	{
		next_row++;
		option_row = next_row;
		for (int i = 0; i < options.size(); i++) {
			setCursor(5, next_row, next_row);
			if (i == cursor_position) {
				setColor(169);
				cout << "　";
				setColor();
			}
			else {
				cout << "　";
			}
			cout << "  " << "< " << options.at(i) << " >";
		}
	}

	// Description Block //
	{
		++++next_row;
		setCursor(3, next_row, next_row);
		cout << "☆☆☆選項說明☆☆☆";	// 40 half-width words and 2 half-width spaces
		description_row = ++next_row;
		setCursor(5, next_row, next_row);
		cout << option_descriptions.at(cursor_position);
		setCursor(0, next_row + 1, next_row);
	}

	int input;
	while (input = _getch(), input != 13) {
		switch (input) {
		case 72:	// ↑
			// option //
			setCursor(5, option_row + cursor_position, next_row);
			setColor();
			cout << "　";
			setCursor(4, description_row, next_row);
			for (int i = 0; i < option_descriptions.at(cursor_position).length() + 5; i++) {
				cout << " ";
			}
			if (cursor_position > 0) {
				--cursor_position;
			}
			else {
				cursor_position = options.size() - 1;
			}
			setCursor(5, option_row + cursor_position, next_row);
			setColor(169);
			cout << "　";
			setColor();

			// description //
			setCursor(5, description_row, next_row);
			cout << option_descriptions.at(cursor_position);
			setCursor(0, next_row + 1, next_row);

			break;

		case 80:	// ↓
			setCursor(5, option_row + cursor_position, next_row);
			setColor();
			cout << "　";
			setCursor(4, description_row, next_row);
			for (int i = 0; i < option_descriptions.at(cursor_position).length() + 5; i++) {
				cout << " ";
			}
			if (cursor_position < options.size() - 1) {
				++cursor_position;
			}
			else {
				cursor_position = 0;
			}
			setCursor(5, option_row + cursor_position, next_row);
			setColor(169);
			cout << "　";
			setColor();

			// description //
			setCursor(5, description_row, next_row);
			cout << option_descriptions.at(cursor_position);
			setCursor(0, next_row + 1, next_row);

			break;
		case 27:	// esc
			return -1;
			break;
		default:
			continue;
		}
	}
	return cursor_position;
}
