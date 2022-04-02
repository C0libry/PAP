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
	bool isCeilingCollide = false;
	bool isRightSideCollide = false;
	bool isLeftSideCollide = false;
	bool lookLeft;
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
	void enemyCollision();
	void drowBorders(RenderWindow& window);
};
