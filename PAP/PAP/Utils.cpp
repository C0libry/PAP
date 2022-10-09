#include "Utils.h"

Loader::~Loader() {};

bool Loader::startLoad()
{
	textureList[0].loadFromFile(HERO_NAME);
	textureList[1].loadFromFile(TILE_ASSETS);
	textureList[2].loadFromFile(SLIME_NAME);
	textureList[3].loadFromFile(HELL_HOUND_IDLE_NAME);
	textureList[4].loadFromFile(HELL_HOUND_JUMP_NAME);
	textureList[5].loadFromFile(HELL_HOUND_RUN_NAME);
	textureList[6].loadFromFile(HELL_HOUND_WALK_NAME);
	return true;
}

Texture& Loader::getTexture(const Objects& obj)
{
	return textureList[obj];
}
