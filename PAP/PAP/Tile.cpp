#include "Tile.h"

Tile::Tile(const Objects& obj, const TileType& type, const int Number, const IntRect& rect, const Vector2f& pos) : Base(obj)
{
	sprite.setTextureRect(rect);
	sprite.setPosition(pos);
	activated = false;
	currentType = type;
	number = Number;
}

void Tile::render(RenderWindow& window)
{
	window.draw(this->sprite);
}

bool Tile::getState()
{
	return activated;
}

void Tile::setState(bool state)
{
	activated = state;
}

TileType Tile::getCurrentType()
{
	return currentType;
}

void Tile::update(Event& event){}
void Tile::eventUpdate(Event& event){}