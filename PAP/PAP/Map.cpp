#include "Map.h"

vector<Tile> Map::map;

list<vector<string>> Map::loadFile()
{
	string fileName = "resources/map/rooms/room 2/lvl 2_physics.csv";

	int lvlNum = 2;

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


	//ifstream f("resources/map/map.txt");
	//ifstream f("resources/map/rooms/TestRoom.txt");
	//ifstream f("resources/map/rooms/test lvl_���� ������ 1.csv");
	//ifstream f("resources/map/rooms/room 2/lvl 2_physics.csv");

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

	//list<vector<string>>::iterator it = lvl.begin();

	//return *it;
	return lvl;
}

void Map::mapCreature(list<vector<string>> lvl)
{
	int roomsInLine = 3;
	int roomsInRow = 2;

	list<vector<string>>::iterator it = lvl.begin();

	vector<string> str = *it;

	vector<int> intmap;
	//vector<string> s;
	//cout << str[str.size()1][str[1].size()-1] << 's';
	for (int roomLine = 0; roomLine < roomsInRow; roomLine++)
	{
		for (int roomRow = 0; roomRow < roomsInLine; roomRow++)
		{
			it = lvl.begin();
			levelCreature(*it, intmap, roomRow, roomLine, BACKGROUND);
			it++;
			levelCreature(*it, intmap, roomRow, roomLine, DECOR);
			it++;
			levelCreature(*it, intmap, roomRow, roomLine, SOLID);
		}
	}

	/*
	for (int line = 0; line < str.size(); line++)
	{
		for (int row = 0; row < str[line].size(); row++)
		{
			if (str[line][row] == '1')
			{
				map.push_back(Tile(BOX, IntRect(0, 0, 16, 16), Vector2f(tileSize * row / 2, tileSize * line)));
			}
		}
	}*/
}

void Map::levelCreature(vector<string>& str, vector<int>& intmap, const int& roomRow, const int& roomLine, const TileType tileType)
{
	int tileSize = 16;
	int roomSize = 32;
	int row = 0;
	int tileLine = 0;
	int tileRow = 0;
	string temp;

	for (int line = 0; line < str.size(); line++)
	{
		row = 0;
		for (int j = 0; j < str[line].size(); j++)
		{
			//row = j;
			//cout << str[i][j];
			if (str[line][j] == ',' || j + 1 == str[line].size())
			{
				if (j + 1 == str[line].size())
				{
					temp += str[line][j];
				}
				intmap.push_back(stoi(temp));
				//line += roomLine * roomSize;
				//row += roomRow * roomSize;
				//map.push_back(Tile(ASSETS, IntRect(0, 0, 16, 16), Vector2f(tileSize * row / 2, tileSize * line)));
				if (intmap[intmap.size() - 1] != -1)
				{
					tileRow = intmap[intmap.size() - 1];
					while (tileRow > 23)
					{
						tileRow = tileRow - 23;
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
	//textureList[i].loadFromFile(HERO_NAME, IntRect(X, Y, ������, ������));
	//textureList[0].loadFromFile(HERO_NAME);
	//textureList[1].loadFromFile(TILE_BOX);

	//string str;
	Sprite& getSprite();
	list<vector<string>> lvl;
	//list<vector<string>> lvl;
	lvl = Map::loadFile();
	Map::mapCreature(lvl);
}

void Map::render(RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		map[i].render(window);
		/*
		if (map[i].getCurrentType() == BACKGROUND)
			map[i].render(window);
		else
			if (map[i].getCurrentType() == DECOR)
				map[i].render(window);
			else
				if (map[i].getCurrentType() == SOLID)
					map[i].render(window);
		*/
	}
}

const vector<Tile>& Map::getMap()
{
	return map;
}