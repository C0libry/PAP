#include "Utils.h"

Loader::~Loader() {};

bool Loader::startLoad()
{
	//textureList[i].loadFromFile(HERO_NAME, IntRect(X, Y, ширина, высота));
	textureList[0].loadFromFile(HERO_NAME);
	textureList[1].loadFromFile(TILE_BOX);
	textureList[2].loadFromFile(SLIME_NAME);

	return true;
}

Texture& Loader::getTexture(const Objects& obj)
{
	return textureList[obj];
}
