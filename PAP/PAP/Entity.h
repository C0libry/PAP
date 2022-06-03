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
	float dx, dy, currentFrame;
	int hp, strength;
	State currentState, newState;
	FloatRect attackHitBox;
	FloatRect borderBottom;
	FloatRect borderRight;
	FloatRect borderLeft;
	FloatRect borderTop;

	Entity(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	void fall();
	void mapCollision();
	//bool isCollide(FloatRect rect1, FloatRect rect2);
	void drowRect(RenderWindow& window, FloatRect rect, Color c);
	void drowRays(RenderWindow& window);
public:
	int gerStrength();
	int getHP();
	void setHP(int HP);
	const FloatRect getAttackHitBox();
};