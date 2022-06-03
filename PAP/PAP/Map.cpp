#include "Map.h"

vector<Tile> Map::map;

vector<string> Map::loadFile()
{
	//ifstream f("resources/map/map.txt");
	//ifstream f("resources/map/rooms/TestRoom.txt");
	//ifstream f("resources/map/rooms/test lvl_���� ������ 1.csv");
	ifstream f("resources/map/rooms/room 2/lvl 2_physics.csv");
	string s;
	vector<string> str;

	while (f) {
		f >> s;
		str.push_back(s);
	}
	return str;
}

void Map::mapCreature(vector<string>& str)
{
	int tileSize = 16;
	int roomSize = 32;
	int roomsInLine = 3;
	int roomsInRow = 2;
	int roomLine = 0;
	int roomRow = 0;
	int line = 0;
	int row = 0;
	int tileLine = 0;
	int tileRow = 0;

	string temp;

	vector<int> intmap;
	//vector<string> s;
	//cout << str[str.size()1][str[1].size()-1] << 's';
	for (int k = 0; k < roomsInRow; k++)
	{
		for (int n = 0; n < roomsInLine; n++)
		{
			for (int i = 0; i < str.size(); i++)
			{
				row = 0;
				for (int j = 0; j < str[i].size(); j++)
				{
					roomLine = k;
					roomRow = n;
					line = i;
					//row = j;
					//cout << str[i][j];
					if (str[i][j] == ',' || j+1 == str[i].size())
					{
						if (j+1 == str[i].size())
						{
							temp += str[i][j];
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
							map.push_back(Tile(ASSETS, SOLID, intmap[intmap.size() - 1], IntRect(tileRow * tileSize, tileLine * tileSize, 16, 16), Vector2f(tileSize * (row + roomRow * roomSize), tileSize * (line + roomLine * roomSize))));
						}
						tileLine = 0;
						tileRow = 0;
						temp = "";
						row ++;
					}
					else
					{
						temp += str[i][j];
					}
				}
			}
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

void Map::load()
{
	//textureList[i].loadFromFile(HERO_NAME, IntRect(X, Y, ������, ������));
	//textureList[0].loadFromFile(HERO_NAME);
	//textureList[1].loadFromFile(TILE_BOX);

	//string str;
	Sprite& getSprite();
	vector<string> str;
	//list<vector<string>> lvl;
	str = Map::loadFile();
	Map::mapCreature(str);
}

void Map::render(RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		map[i].render(window);
	}
}

const vector<Tile>& Map::getMap()
{
	return map;
}