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
			//sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.01);
			sprite.setPosition(sprite.getPosition().x, map[i].getSprite().getPosition().y + map[i].getSprite().getGlobalBounds().height);
			ceilingCollide = true;
		}
		if (borderBottom.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			//sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 0.01);
			sprite.setPosition(sprite.getPosition().x, map[i].getSprite().getPosition().y - sprite.getGlobalBounds().height + lineThickness + 0.1);
			groundCollide = true;
		}
		if (borderRight.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			//sprite.setPosition(sprite.getPosition().x - 0.01, sprite.getPosition().y);
			//sprite.setPosition(map[i].getSprite().getPosition().x, sprite.getPosition().y);
			rightSideCollide = true;
		}
		if (borderLeft.intersects(map[i].getSprite().getGlobalBounds()) && map[i].getSolid())
		{
			//sprite.setPosition(map[i].getSprite().getPosition().y + map[i].getSprite().getGlobalBounds().width, sprite.getPosition().y);
			//sprite.setPosition(sprite.getPosition().x + 0.01, sprite.getPosition().y);
			//sprite.setPosition(map[i].getSprite().getPosition().x + lineThickness - 0.1, sprite.getPosition().y);
			leftSideCollide = true;
		}
	}
	cout << "\n";

	onGround = groundCollide;
	isCeilingCollide = ceilingCollide;
	isRightSideCollide = rightSideCollide;
	isLeftSideCollide = leftSideCollide;
}

//Temp fantion
void Entity::drowRect(RenderWindow& window, FloatRect rect, Color c)
{
	RectangleShape Rect(Vector2f(rect.width, rect.height));
	//ectangleShape rectbot;
	Rect.setFillColor(c);
	//rectbot.setTextureRect(IntRect(bottom));
	Rect.setPosition(rect.left, rect.top);

	window.draw(Rect);
}

//Temp fantion
void Entity::drowRays(RenderWindow& window)
{
	sf::RectangleShape line(sf::Vector2f(150, 10));
	line.rotate(45);
	line.setFillColor(Color::Red);
	window.draw(line);
}

int Entity::gerStrength()
{
	return this->strength;
}

int Entity::getHP()
{
	return this->hp;
}

void Entity::setHP(int HP)
{
	hp = HP;
}

const FloatRect Entity::getAttackHitBox()
{
	return hitBox;
}