#include "Tile.h"

Tile::Tile(const Objects& obj, const IntRect& rect, const Vector2f& pos) : Base(obj)
{
	sprite.setTextureRect(rect);
	sprite.setPosition(pos);
	solid = true;
}

void Tile::render(RenderWindow& window)
{
	window.draw(this->sprite);
}

bool Tile::getSolid()
{
	return solid;
}

void Tile::update(Event& event){}
void Tile::eventUpdate(Event& event){}