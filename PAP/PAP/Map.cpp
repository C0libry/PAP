#include "Map.h"

vector<Tile> Map::map;

vector<string> Map::loadFile()
{
	//ifstream f("resources/map/map.txt");
	ifstream f("resources/map/rooms/TestRoom.txt");
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
	int roomsInLine = 2;
	int roomsInRow = 3;
	int roomLine = 0;
	int roomRow = 0;
	int line = 0;
	int row = 0;

	for (int k = 0; k < roomsInRow; k++)
	{
		for (int n = 0; n < roomsInLine; n++)
		{
			for (int i = 0; i < str.size(); i++)
			{
				for (int j = 0; j < str[i].size(); j++)
				{
					roomLine = k;
					roomRow = n;
					line = i;
					row = j;
					if (str[line][row] == '1')
					{
						line += roomLine * roomSize;
						row += roomRow * roomSize * 2;
						map.push_back(Tile(BOX, IntRect(0, 0, 16, 16), Vector2f(tileSize * row / 2, tileSize * line)));
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
	//textureList[i].loadFromFile(HERO_NAME, IntRect(X, Y, ширина, высота));
	//textureList[0].loadFromFile(HERO_NAME);
	//textureList[1].loadFromFile(TILE_BOX);

	//string str;
	Sprite& getSprite();
	vector<string> str;
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