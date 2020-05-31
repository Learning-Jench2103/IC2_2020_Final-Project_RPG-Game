#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include "Battle.h"
using namespace std;

struct Coordinate {
	int x;
	int y;
	Coordinate();
	Coordinate(int x, int y);
	Coordinate& operator=(const Coordinate& other);
	bool operator==(const Coordinate& other) const;
	bool operator<(const Coordinate& other) const;
};

struct Size {
	int height;
	int width;
	Size();
	Size(int height, int width);
	Size& operator=(const Size& other);
};

// add support for player_mark color
class Grid {
private:
	int symbol = 0;
	string name = "Pavement";
	string mark = "¡½";
	string player_mark = "¡¸";
	string explanation = "";
	unsigned int color = 253;
	string functionPtrType = "nullptr";
	void* function = nullptr;

public:
	Grid();
	Grid(int symbol);	// pre-defined Grid
	Grid(int symbol, string name, string mark, int color);
	Grid(int symbol, string name, string mark, string explanation, int color);
	
	void setSymbol(int symbol);
	int getSymbol() const;
	void setName(string name);
	string getName() const;
	bool setMark(string mark);
	string getMark() const;
	void setExplain(string explanation);
	string getExplain() const;
	void setColor(unsigned int color);
	unsigned int getColor() const;
	void setFunction(string type, void* ptr);
	string getFunctionType() const;
	void* getFunction() const;

	void setGrid(int symbol, string name, unsigned int color);
	void setGrid(int symbol, string name, string mark, unsigned int color);

	bool availableGrid();
	
	void operator=(const Grid& other);

};

class Field {
private:
	string map_name;	// The name of this map
	vector<vector<Grid>> map_data;	// The actual map data with symbolsand items
	Size map_size;	// (height, width)
	Coordinate current_position;	// Current position of player (x, y)
	Size vision_size;	// The width and height of vision (height, width)
	Coordinate start, dest;	// (x, y)
	int bonusPoint = 202;
	string player_mark = "¡¸";

	void setUpMap(int height, int width);

public:
	Field(const string fileName, int v_width, int v_height, int curr_x = -1, int curr_y = -1);
	// if curr_x and curr_y are omitted, the current position will then be set on the start point
	Field(vector<vector<Grid>> map, string name, int v_width, int v_height, int curr_x = -1, int curr_y = -1);
	// The first parameter is the map data
		// The secondand third parameter are the current place(x, y) of player
		// The forthand fifth parameter are the(width, height) of vision
	// if curr_x and curr_y are omitted, the current position will then be set on the start point

	bool move(char key);
	// Move player to next position, the parameter is the direction
		// The return value indicates whether this move is legal or not

	bool moveUp(void);
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);

	bool setPosition(int x, int y);	// Set the position of player, prameters are position(x, y)
	Coordinate getCurrentPosition(void) const;

	void setMapName(string name);
	string getMapName(void) const;

	void setVisionSize(int w, int h);	// Set the size of vision, parameters are(width, height)
	Size getVisionSize(void) const;

	Coordinate getStartPosition() const;
	Coordinate getDestinationPosition() const;

	void setSymbol(int symbol);
	void setSymbol(int symbol, int x, int y);
	int getSymbol() const;
	int getSymbol(int x, int y) const;

	void setSymbolName(string name);
	void setSymbolName(string name, int x, int y);
	string getSymbolName(void) const;
	string getSymbolName(int x, int y) const;

	void setSymbolMark(string mark);
	void setSymbolMark(string mark, int x, int y);

	void setSymbolExplanation(string explanation);
	void setSymbolExplanation(string explanation, int x, int y);
	string getSymbolExplanation() const;
	string getSymbolExplanation(int x, int y) const;

	void setSymbolColor(unsigned int color);
	void setSymbolColor(unsigned int color, int x, int y);

	bool setGrid(int x, int y, int sym, string n, int color);
	bool setGrid(int x, int y, int sym, string n, string m, int color);

	void setPlayerMark(string mark);
	string getPlayerMark() const;

	bool availableGrid(int x, int y);

	void display(void) const;
	// Displaying the map

};

#endif