#pragma once

#include "Include.h"
#include "Tile.h"

class Rooms
{
	Rooms() {}
	//Tile layers[];
};

class Map
{
private:
	static vector<Tile> map;
	static list<vector<Tile>> lvl;
	//static Rooms rooms[ROOMS_NUMBER];
public:
	static vector<string> loadFile();
	static void mapCreature(vector<string>& str);
	static void load();
	static void render(RenderWindow& window);
	static const vector<Tile>& getMap();
	//static void mapUpdate();
};