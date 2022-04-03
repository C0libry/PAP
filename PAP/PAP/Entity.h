#pragma once

#include "Include.h"
#include "Base.h"
#include "level.h"
#include "Tile.h"

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
	FloatRect borderBottom;
	FloatRect borderRight;
	FloatRect borderLeft;
	FloatRect borderTop;

	Entity(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	void fall();
	void mapCollision();
	//bool isCollide(FloatRect rect1, FloatRect rect2);
	void drowBorders(RenderWindow& window);
};
