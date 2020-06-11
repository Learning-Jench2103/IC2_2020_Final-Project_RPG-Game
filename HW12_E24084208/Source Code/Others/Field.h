#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Coordinate {
	int x = 0;
	int y = 0;
	Coordinate();
	Coordinate(int x, int y);
	Coordinate& operator=(const Coordinate& other);
	bool operator==(const Coordinate& other) const;
	bool operator<(const Coordinate& other) const;
};

struct Size {
	int height = 0;
	int width = 0;
	Size();
	Size(int height, int width);
	Size& operator=(const Size& other);
};

struct Grid {
	int symbol = 0;
	string name = "Pavement";
	string mark = "¡½";
	string player_mark = "¡¸";
	string explanation = "";
	unsigned int color = 253;
	string functionPtrType = "nullptr";
	void* function = nullptr;
	bool stepped = false;

	void operator=(const Grid& other);
	void setGrid(int symbol, string name, string mark, unsigned int color);
	void setInfo(string mark, unsigned int color, string explanation);
};

class Field
{
private:
	string map_name;	// The name of this map
	vector<vector<Grid>> map_data;	// The actual map data with symbolsand items
	Size map_size;	// (height, width)
	Coordinate current_position;	// Current position of player (x, y)
	Size vision_size;	// The width and height of vision (height, width)
	string player_mark = "¡¸";
	Coordinate start, dest;
	void setUpMap(int height, int width);

	void setColor(unsigned int color = 7) const;
	void setCursor(int x, int y) const;

public:
	Field(const string fileName, int v_width, int v_height, int curr_x = -1, int curr_y = -1);

	void setGrid(int symbol, string name, string mark, unsigned int color, string explanation);
	void setGrid(Coordinate position, string mark);

	bool move(char key);
	// Move player to next position, the parameter is the direction
		// The return value indicates whether this move is legal or not
	bool moveUp(void);
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);

	void setPosition(int x, int y);
	Coordinate getCurrentPosition(void) const;

	Size getMapSize(void) const;

	Size getVisionSize(void) const;

	int getSymbol() const;
	int getSymbol(int x, int y) const;
	vector<Coordinate> getSymbolCoordinates(int symbol) const;

	string getSymbolName(void) const;
	string getSymbolName(int x, int y) const;

	string getSymbolExplanation() const;
	string getSymbolExplanation(int x, int y) const;

	string getPlayerMark() const;

	bool isStepped() const;
	void step();

	void display(void) const;

};

#endif