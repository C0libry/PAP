#pragma once

#include "Include.h"
#include "Utils.h"

class Base
{
protected:
	static Int64 deltaTime;
	Sprite sprite;
	FloatRect hitBox;
	bool isEndOfAnimation;
	float currentFrame;
	State currentState, newState;
	Base(const Objects& obj);
	virtual ~Base() = 0;
public:
	Sprite& getSprite();
	static const Int64& getDeltaTime();
	static void setDeltaTime(Int64 DeltaTime);
	static float distance(Vector2f point1, Vector2f point2);
	Vector2f getCentrePosition();
	const FloatRect getHitBox();
	FloatRect getSpriteGlobalBounds();

	virtual void render(RenderWindow& window) = 0;
	virtual void update(Event& event) = 0;
	virtual void eventUpdate(Event& event) = 0;
};