#include "Entity.h"

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
		if (borderTop.intersects(map[i].getHitBox()) && map[i].getCurrentType() == SOLID)
		{
			sprite.setPosition(sprite.getPosition().x, map[i].getSprite().getPosition().y + map[i].getSprite().getGlobalBounds().height);
			ceilingCollide = true;
		}
		if (borderBottom.intersects(map[i].getHitBox()) && map[i].getCurrentType() == SOLID)
		{
			sprite.setPosition(sprite.getPosition().x, map[i].getSprite().getPosition().y - sprite.getGlobalBounds().height + lineThickness + 0.1);
			groundCollide = true;
		}
		if (borderRight.intersects(map[i].getHitBox()) && map[i].getCurrentType() == SOLID)
		{
			rightSideCollide = true;
		}
		if (borderLeft.intersects(map[i].getHitBox()) && map[i].getCurrentType() == SOLID)
		{
			leftSideCollide = true;
		}
	}
	cout << "\n";

	onGround = groundCollide;
	isCeilingCollide = ceilingCollide;
	isRightSideCollide = rightSideCollide;
	isLeftSideCollide = leftSideCollide;
}

int Entity::gerStrength()
{
	return this->strength;
}

int Entity::getHP()
{
	return this->hp;
}

bool Entity::getIsAttack()
{
	return this->isAttack;
}

void Entity::setHP(int HP)
{
	hp = HP;
}

const FloatRect Entity::getHitBox()
{
	return hitBox;
}

const FloatRect Entity::getAttackHitBox()
{
	return attackZone;
}