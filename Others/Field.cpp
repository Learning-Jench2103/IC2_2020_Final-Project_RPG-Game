#include "Field.h"
#include <Windows.h>

Coordinate::Coordinate()
{
	x = 0;
	y = 0;
}

Coordinate::Coordinate(int x, int y)
{
	Coordinate::x = x;
	Coordinate::y = y;
}

Coordinate& Coordinate::operator=(const Coordinate& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

bool Coordinate::operator==(const Coordinate& other) const
{
	return x == other.x && y == other.y;
}

bool Coordinate::operator<(const Coordinate& other) const
{
	if (*this == other) {
		return false;
	}
	if (y < other.y) {
		return true;
	}
	if (y > other.y) {
		return false;
	}
	if (x < other.x) {
		return true;
	}
	if (x > other.x) {
		return false;
	}
	else {
		return false;
	}
}

Size::Size()
{
	height = 0;
	width = 0;
}

Size::Size(int height, int width)
{
	Size::height = height;
	Size::width = width;
}

Size& Size::operator=(const Size& other)
{
	height = other.height;
	width = other.width;
	return *this;
}

void Grid::operator=(const Grid& other)
{
	symbol = other.symbol;
	name = other.name;
	mark = other.mark;
	player_mark = other.player_mark;
	explanation = other.explanation;
	color = other.color;
	functionPtrType = other.functionPtrType;
	function = other.function;
}



void Grid::setGrid(int symbol, string name, string mark, unsigned int color)
{
	Grid::symbol = symbol;
	Grid::name = name;
	Grid::mark = mark;
	Grid::color = color;
}

void Grid::setInfo(string mark, unsigned int color, string explanation)
{
	Grid::mark = mark;
	Grid::color = color;
	Grid::explanation = explanation;
}

void Field::setUpMap(int height, int width)
{
	map_data.resize(width);
	for (int i = 0; i < width; i++) {
		map_data.at(i).resize(height);
	}
	map_size.height = height;
	map_size.width = width;
}

Field::Field(const string fileName, int v_width, int v_height, int curr_x, int curr_y)
	:vision_size(v_height, v_width)
{
	stringstream ss;
	int n = fileName.find('.');
	map_name = string(fileName, 0, n);

	fstream file;
	string input;

	file.open(fileName, ios::in);

	if (!file) {
		cout << "檔案 " << fileName << " 未找到！\n";
		exit(1);
	}

	// get height and width of the maze from the file //
	int index_old = -1;
	getline(file, input);

	ss << string(input.begin() + input.find(',') + 1, input.end());
	ss >> map_size.width;
	ss.str("");
	ss.clear();

	ss << string(input, 0, input.find(','));
	ss >> map_size.height;
	ss.str("");
	ss.clear();

	setUpMap(map_size.height, map_size.width);

	// read and store the maze into the program //
	for (int y = 0; y < map_size.height; y++) {
		string input;
		getline(file, input);
		int begin = -1;
		int end;
		for (int x = 0; x < map_size.width; x++) {
			stringstream ss;
			int temp;
			end = input.find(',', begin + 1);
			if (end >= 0) {
				ss << string(input, begin + 1, end - begin - 1);
			}
			else {
				ss << string(input, begin + 1, input.length() - begin - 1);
			}
			ss >> temp;
			ss.str(""); ss.clear();
			/*
			switch (temp) {
			case 0:
				map_data[x][y].setGrid(0, "Pavement", "■", 250);
				break;
			case 1:
				map_data[x][y].setGrid(1, "Wall", "■", 240);
				break;
			case 200:
				map_data[x][y].setGrid(200, "Start", "■", 252);
				start = Coordinate(x, y);
				break;
			case 201:
				map_data[x][y].setGrid(201, "Destination", "■", 249);
				dest = Coordinate(x, y);
				break;
			default:
				map_data[x][y].setSymbol(temp);
			}
			map_data[x][y].setSymbol(temp);
			*/
			if (temp == 0) {
				map_data[x][y].setGrid(0, "Pavement", "■", 250);

			}
			else if (temp == 1) {
				map_data[x][y].setGrid(1, "Wall", "■", 240);
			}
			else if (temp % 100 == 0) {
				map_data[x][y].setGrid(temp, "Start", "■", 252);
				start = Coordinate(x, y);
			}
			else if (temp % 100 == 1) {
				map_data[x][y].setGrid(temp, "Destination", "■", 249);
				dest = Coordinate(x, y);
			}
			else {
				map_data[x][y].symbol = temp;
			}
			begin = end;
		}
	}

	file.close();
	if (curr_x >= 0 && curr_y >= 0) {
		current_position.x = curr_x;
		current_position.y = curr_y;
	}
	else {
		current_position = start;
	}
}

void Field::setGrid(int symbol, string name, string mark, unsigned int color, string explanation)
{
	for (int x = 0; x < map_data.size(); x++) {
		for (int y = 0; y < map_data.at(x).size(); y++) {
			if (map_data.at(x).at(y).symbol == symbol) {
				map_data.at(x).at(y).name = name;
				map_data.at(x).at(y).mark = mark;
				map_data.at(x).at(y).color = color;
				map_data.at(x).at(y).explanation = explanation;
			}
		}
	}
}

void Field::setGrid(Coordinate position, string mark)
{
	map_data.at(position.x).at(position.y).mark = mark;
}

bool Field::move(char key)
{
	switch (key) {
	case 'w':
		if (map_data[current_position.x][current_position.y - 1].symbol == 1) {
			return false;
		}
		else {
			--current_position.y;
		}
		break;
	case 'a':
		if (map_data[current_position.x - 1][current_position.y].symbol == 1) {
			return false;
		}
		else {
			--current_position.x;
		}
		break;
	case 's':
		if (map_data[current_position.x][current_position.y + 1].symbol == 1) {
			return false;
		}
		else {
			++current_position.y;
		}
		break;
	case 'd':
		if (map_data[current_position.x + 1][current_position.y].symbol == 1) {
			return false;
		}
		else {
			++current_position.x;
		}
		break;
	}
	return true;
}

bool Field::moveUp(void)
{
	return move('w');
}

bool Field::moveDown(void)
{
	return move('s');
}

bool Field::moveLeft(void)
{
	return move('a');
}

bool Field::moveRight(void)
{
	return move('d');
}

void Field::setPosition(int x, int y)
{
	if (map_data.at(x).at(y).symbol != 1) {
		current_position.x = x;
		current_position.y = y;
	}
}

Coordinate Field::getCurrentPosition(void) const
{
	return current_position;
}

Size Field::getMapSize(void) const
{
	return map_size;
}

Size Field::getVisionSize(void) const
{
	return vision_size;
}

int Field::getSymbol() const
{
	return map_data.at(current_position.x).at(current_position.y).symbol;
}

int Field::getSymbol(int x, int y) const
{
	return map_data.at(x).at(y).symbol;
}

vector<Coordinate> Field::getSymbolCoordinates(int symbol) const
{
	vector<Coordinate> result;
	for (int x = 0; x < map_data.size(); x++) {
		for (int y = 0; y < map_data.at(x).size(); y++) {
			if (map_data.at(x).at(y).symbol == symbol) {
				result.push_back(Coordinate(x, y));
			}
		}
	}
	return result;
}

string Field::getSymbolName(void) const
{
	return map_data.at(current_position.x).at(current_position.y).name;
}

string Field::getSymbolName(int x, int y) const
{
	return map_data.at(x).at(y).name;
}

string Field::getSymbolExplanation() const
{
	return map_data.at(current_position.x).at(current_position.y).explanation;
}

string Field::getSymbolExplanation(int x, int y) const
{
	return map_data.at(x).at(y).explanation;
}

string Field::getPlayerMark() const
{
	return map_data.at(current_position.x).at(current_position.y).player_mark;
}

bool Field::isStepped() const
{
	return map_data.at(current_position.x).at(current_position.y).stepped;
}

void Field::step()
{
	map_data.at(current_position.x).at(current_position.y).stepped = true;
}

void Field::display(void) const
{
	// decide the displaying range //
	Coordinate range_begin, range_end;
	if (current_position.x - (vision_size.width / 2) < 0) {
		range_begin.x = 0;
	}
	else {
		range_begin.x = current_position.x - (vision_size.width / 2);
	}
	if (current_position.y - (vision_size.height / 2) < 0) {
		range_begin.y = 0;
	}
	else {
		range_begin.y = current_position.y - (vision_size.height / 2);
	}

	if ((range_begin.x + vision_size.width - 1) < map_size.width) {
		range_end.x = range_begin.x + vision_size.width - 1;
	}
	else {
		range_end.x = map_size.width - 1;
		range_begin.x = map_size.width - vision_size.width;
	}
	if ((range_begin.y + vision_size.height - 1) < map_size.height) {
		range_end.y = range_begin.y + vision_size.height - 1;
	}
	else {
		range_end.y = map_size.height - 1;
		range_begin.y = map_size.height - vision_size.height;
	}

	// print map //
	setCursor(4, 1);
	cout << map_name;
	setCursor(2, 3);
	//cout << "  ";
	for (int column = 0; column < vision_size.width; column++) {
		cout << "▁";	// fullwidth
	}
	cout << "\n";

	for (int row = range_begin.y; row <= range_end.y; row++) {
		cout << "▕";	// fullwidth
		for (int column = range_begin.x; column <= range_end.x; column++) {
			if (current_position == Coordinate(column, row)) {
				setColor(map_data.at(column).at(row).color);
				cout << map_data.at(column).at(row).player_mark;
				setColor();
			}
			else {
				setColor(map_data[column][row].color);
				cout << map_data[column][row].mark;
				setColor();
			}
		}
		setColor();
		cout << "▏\n";	// fullwidth
	}

	cout << "  ";
	for (int column = 0; column < vision_size.width; column++) {
		cout << "▔";	// fullwidth
	}
	cout << "\n\n";

	cout << "  移動位置：w,a,s,d或↑↓←→  查看隊員：p  查看背包：b  退出：Esc";

	cout << "\n\n";

	cout << "  " << map_data.at(current_position.x).at(current_position.y).explanation << "\n\n";

	return;
}

void Field::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Field::setCursor(int x, int y) const {
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}
