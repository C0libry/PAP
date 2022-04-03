#include "Enemy.h"

Enemy::Enemy(const Objects& obj, const IntRect& rect, const Vector2f& pos, Player& p) : Entity(obj, rect, pos)
{
	player = &p;
}