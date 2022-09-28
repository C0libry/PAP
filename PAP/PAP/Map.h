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
	static list<vector<string>> loadFile();
	static void mapCreature(list<vector<string>> lvl);
	static void levelCreature(vector<string>& str, vector<int>& intmap, const int& roomRow, const int& roomLine, const TileType tileType);
	static void load();
	static void render(RenderWindow& window);
	static void update(Event event);
	static vector<Tile>& getMap();
	//static void mapUpdate();
};