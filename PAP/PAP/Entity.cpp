#include "Entity.h"
#include "Map.h"

Entity::Entity(const Objects& obj, const IntRect& rect, const Vector2f& pos) : Base(obj)
{
	life = true;
	dx = 0;
	dy = 0;
	onGround = false;
	isCeilingCollide = false;
	isRightSideCollide = false;
	isLeftSideCollide = false;
	isAttack = false;
	currentFrame = 0;
	currentState = STAND;
	lookLeft = true;
	sprite.setTextureRect(rect);
	sprite.setPosition(pos);
}

void Entity::fall()
{
	if (!onGround)
	{
		dy = dy + GRAVITY * deltaTime;
		sprite.move(0, 3 * dy * deltaTime);
		if (dy > 1) dy = 1;
	}
	else
		dy = 0;
}

void Entity::mapCollision()
{
	vector<Tile> map = Map::getMap();
	bool groundCollide = false;
	bool ceilingCollide = false;
	bool rightSideCollide = false;
	bool leftSideCollide = false;

	float lineThickness = 1;

	borderTop.left = hitBox.left;
	borderTop.top = hitBox.top;
	borderTop.width = hitBox.width;
	borderTop.height = -lineThickness;

	borderBottom.left = hitBox.left;
	borderBottom.top = hitBox.top + hitBox.height;
	borderBottom.width = hitBox.width;
	borderBottom.height = lineThickness;

	borderRight.left = hitBox.left + hitBox.width;
	borderRight.top = hitBox.top;
	borderRight.width = lineThickness;
	borderRight.height = hitBox.height;

	borderLeft.left = hitBox.left;
	borderLeft.top = hitBox.top;
	borderLeft.width = -lineThickness;
	borderLeft.height = hitBox.height;

	for (int i = 0; i < map.size(); i++)
	{
		if (borderTop.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.01);
			ceilingCollide = true;
		}
		if (borderBottom.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 0.01);
			groundCollide = true;
		}
		if (borderRight.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			sprite.setPosition(sprite.getPosition().x - 0.01, sprite.getPosition().y);
			rightSideCollide = true;
		}
		if (borderLeft.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			sprite.setPosition(sprite.getPosition().x + 0.01, sprite.getPosition().y);
			leftSideCollide = true;
		}
		hitBox = sprite.getGlobalBounds();
	}
	cout << "\n";

	onGround = groundCollide;
	isCeilingCollide = ceilingCollide;
	isRightSideCollide = rightSideCollide;
	isLeftSideCollide = leftSideCollide;
}

void Entity::drowBorders(RenderWindow& window)
{
	RectangleShape rectBottom(Vector2f(borderBottom.width, borderBottom.height));
	RectangleShape rectRight(Vector2f(borderRight.width, borderRight.height));
	RectangleShape rectLeft(Vector2f(borderLeft.width, borderLeft.height));
	RectangleShape rectTop(Vector2f(borderTop.width, borderTop.height));
	//ectangleShape rectbot;
	rectBottom.setFillColor(Color::Magenta);
	rectRight.setFillColor(Color::Yellow);
	rectLeft.setFillColor(Color::Cyan);
	rectTop.setFillColor(Color::Red);
	//rectbot.setTextureRect(IntRect(bottom));
	rectBottom.setPosition(borderBottom.left, borderBottom.top);
	rectRight.setPosition(borderRight.left, borderRight.top);
	rectLeft.setPosition(borderLeft.left, borderLeft.top);
	rectTop.setPosition(borderTop.left, borderTop.top);

	window.draw(rectBottom);
	window.draw(rectRight);
	window.draw(rectLeft);
	window.draw(rectTop);
}
