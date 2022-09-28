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

void Tile::update(Event& event)
{
	hitBox = FloatRect(sprite.getGlobalBounds());
	hitBox.height = 16;
	hitBox.width = 16;

	if (currentType == TileType::COIN)
	{
		Animator::animation(STAND, currentState, this->sprite, true, 0, 16, 19, currentFrame);
		hitBox = FloatRect(sprite.getGlobalBounds());

		hitBox.top += 4;
		hitBox.height -= (4 + 4);
		hitBox.left += 4;
		hitBox.width -= (4 + 4);
	}
}
void Tile::eventUpdate(Event& event){}