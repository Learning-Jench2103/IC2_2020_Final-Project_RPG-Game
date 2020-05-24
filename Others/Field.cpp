#include "Field.h"

enum { PAVEMENT = 0, WALL = 1, STARTPOINT = 200, DESTPOINT = 201 };

void setColor(unsigned int color = 7) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

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

Grid::Grid()
{
}

Grid::Grid(int symbol)
{
	Grid::symbol = symbol;
}

Grid::Grid(int symbol, string name, string mark, int color)
{
	Grid::symbol = symbol;
	Grid::name = name;
	Grid::mark = mark;
	Grid::color = color;
}

Grid::Grid(int symbol, string name, string mark, string explanation, int color)
{
	Grid::symbol = symbol;
	Grid::name = name;
	Grid::mark = mark;
	Grid::explanation = explanation;
	Grid::color = color;
}

void Grid::setSymbol(int symbol)
{
	Grid::symbol = symbol;
}

int Grid::getSymbol() const
{
	return symbol;
}

void Grid::setName(string name)
{
	Grid::name = name;
}

string Grid::getName() const
{
	return name;
}

bool Grid::setMark(string mark)
{
	if (mark.length() != 2) {
		return false;
	}
	Grid::mark = mark;
	return true;
}

string Grid::getMark() const
{
	return mark;
}

void Grid::setExplain(string explanation)
{
	Grid::explanation = explanation;
}

string Grid::getExplain() const
{
	return explanation;
}

void Grid::setColor(unsigned int color)
{
	Grid::color = color;
}

unsigned int Grid::getColor() const
{
	return color;
}

void Grid::setFunction(string type, void* ptr)
{
	functionPtrType = type;
	function = ptr;
}

string Grid::getFunctionType() const
{
	return functionPtrType;
}

void* Grid::getFunction() const
{
	return function;
}

void Grid::setGrid(int symbol, string name, unsigned int color)
{
	Grid::symbol = symbol;
	Grid::name = name;
	Grid::color = color;
}

void Grid::setGrid(int symbol, string name, string mark, unsigned int color)
{
	Grid::symbol = symbol;
	Grid::name = name;
	Grid::mark = mark;
	Grid::color = color;
}

bool Grid::availableGrid()
{
	return symbol == 0;
}

void Grid::operator=(const Grid& other)
{
	symbol = other.symbol;
	name = other.name;
	mark = other.mark;
	explanation = other.explanation;
	color = other.color;
	functionPtrType = other.functionPtrType;
	function = other.function;
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
		cout << "ÀÉ®× " << fileName << " ¥¼§ä¨ì¡I\n";
		exit(1);
	}

	// get height and width of the maze from the file //
	int index_old = -1;
	getline(file, input);

	ss << string(input.begin() + input.find(',') + 1, input.end());
	ss >> map_size.height;
	ss.str("");
	ss.clear();

	ss << string(input, 0, input.find(','));
	ss >> map_size.width;
	ss.str("");
	ss.clear();

	setUpMap(map_size.height, map_size.width);
	setVisionSize(v_height, v_width);

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
			switch (temp) {
			case 0:
				map_data[x][y].setGrid(0, "Pavement", "¡½", 250);
				break;
			case 1:
				map_data[x][y].setGrid(1, "Wall", "¡½", 240);
				break;
			case 200:
				map_data[x][y].setGrid(200, "Start", "¡½", 252);
				start = Coordinate(x, y);
				break;
			case 201:
				map_data[x][y].setGrid(201, "Destination", "¡½", 249);
				dest = Coordinate(x, y);
				break;
			default:
				map_data[x][y].setSymbol(temp);
			}
			map_data[x][y].setSymbol(temp);
			begin = end;
		}
	}

	file.close();
	if (curr_x >= 0 && curr_y >= 0) {
		setPosition(curr_x, curr_y);
	}
	else {
		setPosition(start.x, start.y);
	}
}

Field::Field(vector<vector<Grid>> map, string name, int v_width, int v_height, int curr_x, int curr_y)
{
	map_name = name;
	map_data = map;
	map_size = Size(v_height, v_width);
	for (int x = 0; x < map_size.width; x++) {
		for (int y = 0; y < map_size.height; y++) {
			if (map_data.at(x).at(y).getSymbol() == 200) {
				start = Coordinate(x, y);
			}
			if (map_data.at(x).at(y).getSymbol() == 201) {
				dest = Coordinate(x, y);
			}
			if (map_data.at(x).at(y).getSymbol() >= bonusPoint) {
				bonusPoint = map_data.at(x).at(y).getSymbol() + 1;
			}
		}
	}
	if (curr_x >= 0 && curr_y >= 0) {
		current_position = Coordinate(curr_x, curr_y);
	}
	else {
		current_position = start;
	}
}

bool Field::move(char key)
{
	switch (key) {
	case 'w':
		if (map_data[current_position.x][current_position.y - 1].getSymbol() == WALL) {
			return false;
		}
		else {
			--current_position.y;
		}
		break;
	case 'a':
		if (map_data[current_position.x - 1][current_position.y].getSymbol() == WALL) {
			return false;
		}
		else {
			--current_position.x;
		}
		break;
	case 's':
		if (map_data[current_position.x][current_position.y + 1].getSymbol() == WALL) {
			return false;
		}
		else {
			++current_position.y;
		}
		break;
	case 'd':
		if (map_data[current_position.x + 1][current_position.y].getSymbol() == WALL) {
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

bool Field::setPosition(int x, int y)
{
	if (x < 0 || x >= map_size.width || y < 0 || y >= map_size.height) {
		return false;
	}
	if (map_data[x][y].getSymbol() == WALL) {
		return false;
	}
	current_position.x = x;
	current_position.y = y;
	return true;
}

Coordinate Field::getCurrentPosition(void) const
{
	return current_position;
}

void Field::setMapName(string name)
{
	map_name = name;
}

string Field::getMapName(void) const
{
	return map_name;
}

void Field::setVisionSize(int w, int h)
{
	vision_size = Size(h, w);
}

Size Field::getVisionSize(void) const
{
	return vision_size;
}

Coordinate Field::getStartPosition() const
{
	return start;
}

Coordinate Field::getDestinationPosition() const
{
	return dest;
}

void Field::setSymbol(int symbol)
{
	map_data[current_position.x][current_position.y].setSymbol(symbol);
}

void Field::setSymbol(int symbol, int x, int y)
{
	map_data[x][y].setSymbol(symbol);
}

int Field::getSymbol() const
{
	return map_data[current_position.x][current_position.y].getSymbol();
}

int Field::getSymbol(int x, int y) const
{
	return map_data[x][y].getSymbol();
}

void Field::setSymbolName(string name)
{
	map_data[current_position.x][current_position.y].setName(name);
}

void Field::setSymbolName(string name, int x, int y)
{
	map_data[x][y].setName(name);
}

string Field::getSymbolName(void) const
{
	return map_data[current_position.x][current_position.y].getName();
}

string Field::getSymbolName(int x, int y) const
{
	return map_data[x][y].getName();
}

void Field::setSymbolMark(string mark)
{
	map_data[current_position.x][current_position.y].setMark(mark);
}

void Field::setSymbolMark(string mark, int x, int y)
{
	map_data[x][y].setMark(mark);
}

void Field::setSymbolExplanation(string explanation)
{
	map_data[current_position.x][current_position.y].setExplain(explanation);
}

void Field::setSymbolExplanation(string explanation, int x, int y)
{
	map_data[x][y].setExplain(explanation);
}

string Field::getSymbolExplanation() const
{
	return map_data[current_position.x][current_position.y].getExplain();
}

string Field::getSymbolExplanation(int x, int y) const
{
	return map_data[x][y].getExplain();
}

void Field::setSymbolColor(unsigned int color)
{
	map_data[current_position.x][current_position.y].setColor(color);
}

void Field::setSymbolColor(unsigned int color, int x, int y)
{
	map_data[x][y].setColor(color);
}

bool Field::setGrid(int x, int y, int sym, string n, int color)
{
	if (x < 0 || y < 0) {
		return false;
	}
	if (x >= map_size.width || y >= map_size.height) {
		return false;
	}
	map_data[x][y].setSymbol(sym);
	map_data[x][y].setName(n);
	map_data[x][y].setColor(color);
	return true;
}

bool Field::setGrid(int x, int y, int sym, string n, string m, int color)
{
	if (x < 0 || y < 0) {
		return false;
	}
	if (x >= map_size.width || y >= map_size.height) {
		return false;
	}
	map_data[x][y].setSymbol(sym);
	map_data[x][y].setName(n);
	map_data[x][y].setMark(m);
	map_data[x][y].setColor(color);
	return true;
}

void Field::setPlayerMark(string mark)
{
	player_mark = mark;
}

string Field::getPlayerMark() const
{
	return player_mark;
}

bool Field::availableGrid(int x, int y)
{
	if (x >= map_size.width || y >= map_size.height || x < 0 || y < 0) {
		return false;
	}
	return map_data[x][y].getSymbol() != WALL;
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
	cout << "  ";
	for (int column = 0; column < vision_size.width; column++) {
		cout << "¢b";	// fullwidth
	}
	cout << "\n";

	for (int row = range_begin.y; row <= range_end.y; row++) {
		cout << "¢y";	// fullwidth
		for (int column = range_begin.x; column <= range_end.x; column++) {
			if (current_position == Coordinate(column, row)) {
				switch (map_data[column][row].getColor()) {
				case PAVEMENT:
					setColor(160);
					break;
				case STARTPOINT:
					setColor(192);
					break;
				case DESTPOINT:
					setColor(144);
					break;
				default:
					setColor(208);
					break;
				}
				cout << player_mark;	// fullwidth
			}
			else {
				setColor(map_data[column][row].getColor());
				cout << map_data[column][row].getMark();
			}
		}
		setColor();
		cout << "¢j\n";	// fullwidth

	}
	setColor();

	cout << "  ";
	for (int column = 0; column < vision_size.width; column++) {
		cout << "¢v";	// fullwidth
	}
	cout << "\n";

	return;
}


