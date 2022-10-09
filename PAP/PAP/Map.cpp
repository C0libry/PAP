#include "Map.h"

vector<Tile> Map::map;

list<vector<string>> Map::loadFile()
{
	string fileName = "resources/map/rooms/room 4/lvl 4_physics.csv";

	int lvlNum = 4;

	string temp;
	temp = "resources/map/rooms/room ";
	temp += to_string(lvlNum);
	temp += "/lvl ";
	temp += to_string(lvlNum);

	string doors = temp + "_doors.csv";
	string objects = temp + "_objects.csv";
	string physics = temp + "_physics.csv";
	string decor = temp + "_decor.csv";
	string background = temp + "_background.csv";

	list<vector<string>> lvl;
	vector<string> str;
	string s;

	ifstream Background(background);
	while (Background) {
		Background >> s;
		str.push_back(s);
	}
	Background.close();
	lvl.push_back(str);
	str.clear();
	s.clear();

	ifstream Decor(decor);
	while (Decor) {
		Decor >> s;
		str.push_back(s);
	}
	Decor.close();
	lvl.push_back(str);
	str.clear();
	s.clear();

	ifstream Physics(physics);
	while (Physics) {
		Physics >> s;
		str.push_back(s);
	}
	Physics.close();
	lvl.push_back(str);
	str.clear();
	s.clear();

	ifstream Objects(objects);
	while (Objects) {
		Objects >> s;
		str.push_back(s);
	}
	Objects.close();
	lvl.push_back(str);
	str.clear();
	s.clear();

	return lvl;
}

void Map::mapCreature(list<vector<string>> lvl)
{
	int roomsInLine = 2;
	int roomsInRow = 1;

	list<vector<string>>::iterator it = lvl.begin();

	vector<string> str = *it;

	vector<int> intmap;

	for (int roomLine = 0; roomLine < roomsInRow; roomLine++)
	{
		for (int roomRow = 0; roomRow < roomsInLine; roomRow++)
		{
			it = lvl.begin();
			levelCreature(*it, intmap, roomRow, roomLine, TileType::BACKGROUND);
			it++;
			levelCreature(*it, intmap, roomRow, roomLine, TileType::DECOR);
			it++;
			levelCreature(*it, intmap, roomRow, roomLine, TileType::SOLID);
			it++;
			levelCreature(*it, intmap, roomRow, roomLine, TileType::COIN);
		}
	}
}

void Map::levelCreature(vector<string>& str, vector<int>& intmap, const int& roomRow, const int& roomLine, const TileType tileType)
{
	int tileSize = 16;
	int roomSize = 32;
	int row = 0;
	int tileLine = 0;
	int tileRow = 0;
	string temp;

	for (int line = 0; line < str.size()-1; line++)
	{
		row = 0;
		for (int j = 0; j < str[line].size(); j++)
		{
			if (str[line][j] == ',' || j + 1 == str[line].size())
			{
				if (j + 1 == str[line].size())
				{
					temp += str[line][j];
				}
				intmap.push_back(stoi(temp));
				if (intmap[intmap.size() - 1] != -1)
				{
					tileRow = intmap[intmap.size() - 1];
					while (tileRow > 20)
					{
						tileRow = tileRow - 20;
						tileLine++;
					}
					map.push_back(Tile(ASSETS, tileType, intmap[intmap.size() - 1], IntRect(tileRow * tileSize, tileLine * tileSize, 16, 16), Vector2f(tileSize * (row + roomRow * roomSize), tileSize * (line + roomLine * roomSize))));
				}
				tileLine = 0;
				tileRow = 0;
				temp.clear();
				row++;
			}
			else
			{
				temp += str[line][j];
			}
		}
	}
}

void Map::load()
{
	Sprite& getSprite();
	list<vector<string>> lvl;
	lvl = Map::loadFile();
	Map::mapCreature(lvl);
}

void Map::render(RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		map[i].render(window);
	}
}

void Map::update(Event event)
{
	for (int i = 0; i < map.size(); i++)
	{
		map[i].update(event);
	}
}

vector<Tile>& Map::getMap()
{
	return map;
}