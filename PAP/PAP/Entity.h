#pragma once

#include "Include.h"
#include "Base.h"
#include "level.h"
#include "Tile.h"
#include "Map.h"

class Entity : public Base
{
protected:
	//Переменная которая отвечает за жизнь
	bool life;
	bool onGround;
	bool isCeilingCollide;
	bool isRightSideCollide;
	bool isLeftSideCollide;
	bool lookLeft;
	bool isAttack;
	float dx, dy;
	int hp, strength;
	FloatRect borderBottom;
	FloatRect borderRight;
	FloatRect borderLeft;
	FloatRect borderTop;
	FloatRect attackZone;

	Entity(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	void fall();
	void mapCollision();
public:
	int gerStrength();
	int getHP();
	bool getIsAttack();
	void setHP(int HP);
	const FloatRect getHitBox();
	const FloatRect getAttackHitBox();
	virtual void attack() = 0;
};